QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib

CONFIG += qt staticlib

SOURCES += \
    model.cpp \
    controler.cpp \
    view_geometryengine.cpp \
    view_mainwindow.cpp \
    view_mainwidget.cpp \
    helper_profiling.cpp \
    libmain.cpp

SOURCES +=

HEADERS += \
    libmain.h \
    model.h \
    controler.h \
    view_geometryengine.h \
    view_mainwindow.h \
    view_mainwidget.h \
    helper_profiling.h \
    iview.h \
    icontroler.h

RESOURCES += \
    shaders.qrc \
    textures.qrc \
    icon.qrc

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    view_mainwindow.ui

INCLUDEPATH += $$OUT_PWD/libmain


mac: CONFIG += MAC_CONFIG

#comment next line if code coverage is not needed
MAC_CODE_COVERAGE=USE

MAC_CONFIG {
    CONFIG += c++11
    QMAKE_CXXFLAGS += -std=c++11 -stdlib=libstdc++ -mmacosx-version-min=10.10
    QMAKE_LFLAGS += -std=c++11 -stdlib=libstdc++ -mmacosx-version-min=10.10

    contains(MAC_CODE_COVERAGE, USE) {
        QMAKE_CXXFLAGS += -g -Wall -fprofile-arcs -ftest-coverage -O0
        QMAKE_LFLAGS += -g -Wall -fprofile-arcs -ftest-coverage -O0

        macx: LIBS += -L$$PWD/../../../../../../Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/6.1.0/lib/darwin/ -lclang_rt.profile_osx

        INCLUDEPATH += $$PWD/../../../../../../Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/6.1.0/lib/darwin
        DEPENDPATH += $$PWD/../../../../../../Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/6.1.0/lib/darwin

        macx: PRE_TARGETDEPS += $$PWD/../../../../../../Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/6.1.0/lib/darwin/libclang_rt.profile_osx.a
    }

}




