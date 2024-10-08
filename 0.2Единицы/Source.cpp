#include <iostream>
using namespace std;
unsigned long long m = 1000000007;
unsigned long long factorial(int el) {
	unsigned long long result = 1;
	for (int i = 2; i <= el; i++) {
		result = (result * i) % m;
	}
	return result;
}
unsigned long long f2(int el, int k) {
	unsigned long long result = 1;
	for (int i = 0; i < k; i++) {
		result = (result * (el - i)) % m;
	}
	return result;
}
//fk^(-1) = fk^(p-2)
unsigned long long bin(unsigned long long el, unsigned long long st) {
	unsigned long long res = 1;
	while (st) {
		if (st & 1) 
			res = res * el % m;
		el = el * el % m;
		st >>= 1;
	}
	return res;
}
unsigned long long obr(unsigned long long x) {
	return bin(x, m - 2);
}

int main() {
	int n, k;
	cin >> n >> k;
	long long fn, fk;
	fn = f2(n, k);
	fk = factorial(k);
	unsigned long long kf = obr(fk);
	unsigned long long result = (fn * kf) % m;
	cout << result << endl;
	return 0;
}