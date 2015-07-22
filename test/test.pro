#-------------------------------------------------
#
# Project created by QtCreator 2015-07-13T18:56:34
#
#-------------------------------------------------

QT       += core opengl widgets testlib xmlpatterns

QT       -= gui

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += testcase
TEMPLATE = app


SOURCES += main.cpp \
    fpstest.cpp \
    startuptimetest.cpp \
    waitforupdatedone.cpp \
    xmltestreport.cpp


HEADERS += \
    fpstest.h \
    startuptimetest.h \
    waitforupdatedone.h \
    global.h \
    xmltestreport.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libmain/release/ -llibmain
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libmain/debug/ -llibmain
else:unix: LIBS += -L$$OUT_PWD/../libmain/ -llibmain

INCLUDEPATH += $$PWD/../libmain
DEPENDPATH += $$PWD/../libmain

INCLUDEPATH += $$OUT_PWD/../libmain
DEPENDPATH += $$OUT_PWD/../libmain

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libmain/release/liblibmain.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libmain/debug/liblibmain.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libmain/release/libmain.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libmain/debug/libmain.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libmain/liblibmain.a

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

DISTFILES += \
    testrun.sh
