#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;
	vector <int> A(n);
	for (int i = 0; i < n; i++) {
		in >> A[i];
	}
	if (n == 0) {
		out << 0;
		return 0;
	}
	vector <int> N;
	for (int i = 0; i < n; i++) {
		auto p = lower_bound(N.begin(), N.end(), A[i]);
		if (p == N.end()) {
			N.push_back(A[i]);
		}
		else {
			if (*p - 1 != A[i]) {
				*p = A[i];
			}
		}
	}
	out << N.size();
	return 0;
}