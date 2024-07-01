#include "struct1.h"
#include <QString>
using namespace std;

struct1::struct1(){
    Amount = 0;
    Cost = 0;
    Name = "..";
}
struct1::struct1(int a0, double c0, QString n0) :Amount(a0), Cost(c0), Name(n0) {}
struct1::struct1(const struct1& r) {
    Amount = r.Amount;
    Cost = r.Cost;
    Name = r.Name;
}
