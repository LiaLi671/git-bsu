#include "tas1.h"
#include <vector>
using namespace std;
tas1::tas1(): num(0) {}
tas1::tas1(int a){
    num = a;
}
bool tas1:: is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> tas1::factorize(int num) {
    vector<int> factors;
    for (int i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            factors.push_back(i);
            num /= i;
        }
    }
    if (num > 1) {
        factors.push_back(num);
    }
    return factors;
}

