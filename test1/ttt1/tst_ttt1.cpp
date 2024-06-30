#include <QtTest>
#include "../t2/tas1.h"
#include <vector>
// add necessary includes here

class ttt1 : public QObject
{
    Q_OBJECT

public:
    ttt1();
    ~ttt1();

private slots:
    void test_case1();
};

ttt1::ttt1() {}

ttt1::~ttt1() {}

void ttt1::test_case1() {
    tas1 a;
    int element = 18;
    QCOMPARE(a.is_prime(element), false);
    vector <int> v = a.factorize(element);
    if (a.is_prime(element)){
        int pr = 1;
        for (size_t i = 0; i < v.size(); i++){
            pr*= v.back();
            v.pop_back();
        }
        QCOMPARE(element, pr);
    }
}

QTEST_APPLESS_MAIN(ttt1)

#include "tst_ttt1.moc"
