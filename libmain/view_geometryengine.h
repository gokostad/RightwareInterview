/****************************************************************************
**
** class View_GeometryEngine
**
** Description:
** Rendering cube geometry
**
****************************************************************************/

#ifndef VIEW_GEOMETRYENGINE_H
#define VIEW_GEOMETRYENGINE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class View_GeometryEngine : protected QOpenGLFunctions
{
public:
    View_GeometryEngine();
    virtual ~View_GeometryEngine();

    void drawCubeGeometry(QOpenGLShaderProgram *program);

private:
    void initCubeGeometry();

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
};

#endif // VIEW_GEOMETRYENGINE_H
