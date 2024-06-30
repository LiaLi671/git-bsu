#include "task3.h"
#include <cmath>
#include <vector>
using namespace std;
task3::task3(): a0(0) {}
task3::task3(int a){
    a0 = a;
}
bool task3:: is_solution(double a, double b, double c){
    double d = b * b - 4 * a * c;
    if (d >= 0) return true;
    else if (d < 0) return false;
}
vector <double> task3:: root_find (double a, double b, double c){
    bool flag = is_solution(a, b, c);
    vector <double> v;
    if (flag){
        double d = b * b - 4 * a * c;
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        v.push_back(x1);
        v.push_back(x2);
    }
    return v;
}

