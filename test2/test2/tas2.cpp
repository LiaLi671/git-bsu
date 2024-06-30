#include "tas2.h"
#include <cmath>
using namespace std;

tas2::tas2(): n(0)  {}
tas2::tas2(double n0){
    n = n0;
}
double tas2:: mysin(double x, double e){
    double sum = 0, an, an1, sin0;
    an1 = x;	//первый член ряда при n=0
    sum = an1;
    for (int n = 1; ; n++)
    {
        int del = 1;
        int res = 2 * n + 1;
        for (int k = 2; k <= res; k++)	//находим значение делителя (считаем факториал)
            del = del * k;
        an = pow(-1, n) * pow(x, 2 * n + 1) / del;	//находим последующий член ряда
        if ((an - an1) <= e)
            break;
        else
            sum = sum + an;
        an1 = an;	//значение ряда становится предыдущим значением ряда для последующего an
    }
    sin0 = sin(sum);
    return sin0;
}

