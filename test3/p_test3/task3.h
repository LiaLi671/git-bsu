#pragma once
#include <vector>
using namespace std;
class task3
{   int a0;
public:
    task3();
    task3(int a);
    bool is_solution(double a, double b, double c);
    vector <double> root_find (double a, double b, double c);
};
