#include <QtTest>
#include "../p_test3/task3.h"
#include <vector>
// add necessary includes here

class m_t3 : public QObject
{
    Q_OBJECT

public:
    m_t3();
    ~m_t3();

private slots:
    void test_case1();
};

m_t3::m_t3() {}

m_t3::~m_t3() {}

void m_t3::test_case1() {
    task3 c;
    double a1 = 1, b1 = -2, c1 = 1;
    bool f = c.is_solution(a1, b1, c1);
    QCOMPARE(f, true);
    if (f){
        vector v = c.root_find(a1, b1, c1);
        double x1 = v.back(), x2 = v.back();
        double res1 = a1*x1*x1 + b1*x1 + c1;
        double res2 = a1*x2*x2 + b1*x2 + c1;
        QVERIFY(res1 <= 0.00001);
        QVERIFY(res2 <= 0.00001);
    }
}

QTEST_APPLESS_MAIN(m_t3)

#include "tst_m_t3.moc"
