#include <QtTest>
#include "../test2/tas2.h"
#include <cmath>
// add necessary includes here

class t2 : public QObject
{
    Q_OBJECT

public:
    t2();
    ~t2();

private slots:
    void test_case1();
};

t2::t2() {}

t2::~t2() {}

void t2::test_case1() {
    tas2 b;
    double ug = 3, eps = 0.00001;
    double x1 = b.mysin(ug, eps);
    double x2 = sin(ug);
    QVERIFY(abs(x1-x2)<eps);
}

QTEST_APPLESS_MAIN(t2)

#include "tst_t2.moc"
