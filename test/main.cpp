#include <QTest>
#include <QApplication>
#include <vector>

#include "../libmain/libmain.h"

#include "global.h"
#include "fpstest.h"
#include "startuptimetest.h"
#include "xmltestreport.h"

/*
 * call for xml output example:
 * test -xml -o FileName.xml
 */
int main(int argc, char *argv[])
{
/*** 1. TEST CASE ***/
    // run startup time measuring test
    libmain(argc, argv, [](){
        StartupTimeTest test;
        return QTest::qExec(&test, qApp->arguments());
    });

    //lets find out does user want output in xml file, if yes
    //after every test case we'll rename file.
    //otherwise, by default, every test case will overwrite previous test
    //case result. This should be done after QApplication is
    //constructed in libmain
    QString testOutputFileName;
    QDir dir(".");
    bool outputRequested = false;

    for (int i = 0; i < argc; i++)
    {
        QString o(argv[i]);
        if (o.compare("-o") == 0)
            outputRequested = true;
        else if (outputRequested)
        {
            testOutputFileName = o;
            break;
        }
    }

    //rename xml output if exist
    if (outputRequested)
        dir.rename(testOutputFileName, QDateTime::currentDateTime().toString("yyMMddhhmmss") + "_StartupTest_" + testOutputFileName);


/*** 2. TEST CASE ***/
    // run fps test
    libmain(argc, argv, []() {
        FPSTest test;
        QTest::qExec(&test, qApp->arguments());
        xmlReport.closeReport();
        return 1;
    });

    //rename xml output if exist
    if (outputRequested)
        dir.rename(testOutputFileName, QDateTime::currentDateTime().toString("yyMMddhhmmss") + "_FPSTest_" + testOutputFileName);

    return 1;
}

