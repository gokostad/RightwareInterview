/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "view_mainwidget.h"

/****************************************************************************
**
** class View_MainWidget
**
** Description:
** Main widget, opengl, handling different events on the opengl widget and
** drawing on screen. Doing animation.
**
****************************************************************************/
#include <QApplication>
#include <QMouseEvent>

#include <math.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>

View_MainWidget::View_MainWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    texture(0),
    angularSpeed(0),
    m_stoped(false)
{
    //init random generator, used to put cube on different location when added
    srand (static_cast <unsigned> (time(0)));

    //start moving cube on the start
    QVector3D n = QVector3D(0.3f, 0.3f, 0.3f).normalized();
    //angular speed
    qreal acc = 0.3;
    angularSpeed = 0.1;
    // Calculate new rotation axis as weighted sum
    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();
}

View_MainWidget::~View_MainWidget()
{
    // Make sure the context is current when deleting the texture
    // and the buffers.
    makeCurrent();

    delete texture;
    for_each (geometries.begin(), geometries.end(), [](View_GeometryEngine* p) {delete p;});

    doneCurrent();
}

QString View_MainWidget::getInfoString()
{
    return "Info: [left double click] ADD, [right click] REMOVE cube; "
            "[left mouse press-move-release] CHANGE ROTATION SPEED & DIRECTION";
}

void View_MainWidget::addGeometry()
{
    geometries.push_back(new View_GeometryEngine());
    update();
}

void View_MainWidget::removeGeometry()
{
    if (geometries.size() > 0)
    {
        geometries.pop_back();
        update();
    }
}

size_t View_MainWidget::geometryCount()
{
    return geometries.size();
}

void View_MainWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
    //adding cube on double click
    if (e->button() == Qt::MouseButton::LeftButton)
        addGeometry();
}

void View_MainWidget::mousePressEvent(QMouseEvent *e)
{
    //remove cube
    if (e->button() == Qt::MouseButton::RightButton)
        removeGeometry();

    // Save mouse press position
    if (e->button() == Qt::MouseButton::LeftButton)
        mousePressPosition = QVector2D(e->localPos());
}

void View_MainWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (m_stoped && QApplication::mouseButtons() == Qt::MouseButton::LeftButton)
    {
        // Mouse release position - mouse press position
        QVector2D diff = QVector2D(e->localPos()) - mousePressPosition;

        // Rotation axis is perpendicular to the mouse position difference
        // vector
        QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();

        // Accelerate angular speed relative to the length of the mouse sweep
        qreal acc = diff.length() / 100.0;

        // Calculate new rotation axis as weighted sum
        rotationAxis = (rotationAxis * 1 + n * acc).normalized();

        rotation = QQuaternion::fromAxisAndAngle(rotationAxis, 1) * rotation;

        mousePressPosition = QVector2D(e->localPos());

        update();
    }
}

void View_MainWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::MouseButton::LeftButton && !m_stoped)
    {
        // Mouse release position - mouse press position
        QVector2D diff = QVector2D(e->localPos()) - mousePressPosition;

        // Rotation axis is perpendicular to the mouse position difference
        // vector
        QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();

        // Accelerate angular speed relative to the length of the mouse sweep
        qreal acc = diff.length() / 100.0;

        // Calculate new rotation axis as weighted sum
        rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

        // Increase angular speed
        angularSpeed += acc;
    }
}

void View_MainWidget::timerEvent(QTimerEvent *)
{
    if (!m_stoped)
    {
        //never stop completly, only be request on fps press
        if (angularSpeed > 0.1)
        {
            // Decrease angular speed (friction)
            angularSpeed *= 0.997;
        }
        if (angularSpeed < 0.1) {
            angularSpeed = 0.1;
            // Rotation axis is perpendicular to the mouse position difference vector
            QVector3D n = QVector3D(static_cast <float> (rand() / static_cast <float> (RAND_MAX)),
                                    static_cast <float> (rand() / static_cast <float> (RAND_MAX)),
                                    static_cast <float> (rand() / static_cast <float> (RAND_MAX))).normalized();

            // Accelerate angular speed relative to the length of the mouse sweep
            qreal acc = 0.3;

            // Calculate new rotation axis as weighted sum
            rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();
            rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;
        }
        else
        {
            // Update rotation
            rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;
        }
        // Request an update
        update();
    }
}

void View_MainWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    initShaders();
    initTextures();

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable back face culling
    glEnable(GL_CULL_FACE);

    // Use QBasicTimer because its faster than QTimer
    timer.start(0, this);
}

void View_MainWidget::initShaders()
{
    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.glsl"))
        close();

    // Link shader pipeline
    if (!program.link())
        close();

    // Bind shader pipeline for use
    if (!program.bind())
        close();
}

void View_MainWidget::initTextures()
{
    // Load cube.png image
    texture = new QOpenGLTexture(QImage(":/cube.png").mirrored());

    // Set nearest filtering mode for texture minification
    texture->setMinificationFilter(QOpenGLTexture::Nearest);

    // Set bilinear filtering mode for texture magnification
    texture->setMagnificationFilter(QOpenGLTexture::Linear);

    // Wrap texture coordinates by repeating
    // f.ex. texture coordinate (1.1, 1.2) is same as (0.1, 0.2)
    texture->setWrapMode(QOpenGLTexture::Repeat);
}

void View_MainWidget::resizeGL(int w, int h)
{
    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 3.0, zFar = 7.0, fov = 45.0;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.perspective(fov, aspect, zNear, zFar);
}

void View_MainWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    texture->bind();

    // Calculate model view transformation
    QMatrix4x4 matrix;
    matrix.translate(0.0, 0.0, -5.0);
    matrix.rotate(rotation);

    // Set modelview-projection matrix
    program.setUniformValue("mvp_matrix", projection * matrix);

    // Use texture unit 0 which contains cube.png
    program.setUniformValue("texture", 0);

    // Draw cubes geometry
    for_each (geometries.begin(), geometries.end(), [this](View_GeometryEngine* p) { p->drawCubeGeometry(&program); });

    updateDone();
}

