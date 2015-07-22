/****************************************************************************
**
** class StartupTimeTest
**
** Description:
** Declaration of StartupTimeTest test case
**
****************************************************************************/
#ifndef STARTUPTIMETEST_H
#define STARTUPTIMETEST_H

#include <QObject>

class StartupTimeTest : public QObject
{
    Q_OBJECT
public:
    explicit StartupTimeTest(QObject *parent = 0);

signals:

private slots:
    void initTestCase();
    void cleanupTestCase();

    void init();
    void cleanup();

    void test();
};

#endif // STARTUPTIMETEST_H
