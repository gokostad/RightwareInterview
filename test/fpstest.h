/****************************************************************************
**
** class FPSTest
**
** Description:
** Declaration of FPSTest test case
**
****************************************************************************/
#ifndef FPSTest_H
#define FPSTest_H

#include <QObject>

class FPSTest : public QObject
{
    Q_OBJECT
public:
    explicit FPSTest(QObject *parent = 0);

signals:

private slots:
    void initTestCase();
    void cleanupTestCase();

    void init();
    void cleanup();

    void test();
    void test_data();
};

#endif // FPSTest_H
