#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector <int> K0(n);
	for(int i = 0; i < n; i++) {
		cin >> K0[i];
	}
	vector <int> K1(n);
	vector <int> S(n);
	K1[0] = K0[0];
	S[0] = -1;
	if (n == 1) {
		cout << K0[0] << endl;
		cout << 1;
		return 0;
	}
	K1[1] = -1;
	S[1] = -1;
	if(n > 2){
		K1[2] = K0[2] + K0[0];
		S[2] = 0;
		for (int i = 3; i < n; i++) {
			if (K1[i - 2] > K1[i - 3]) {
				K1[i] = K0[i] + K1[i-2];
				S[i] = i - 2;
			}
			else {
				K1[i] = K0[i] + K1[i-3];
				S[i] = i - 3;
			}
		}
		cout << K1[n - 1] << endl;
		vector <int> Answ;
		for (int i = n - 1; i >= 0; i = S[i]) {
			Answ.push_back(i + 1);
			if (S[i] == -1) break;
		}
		for (int i = Answ.size() - 1; i >=0; i--) {
			cout << Answ[i] << " ";
		}
	}
	else if (n == 2) {
		cout << -1;
	}
	return 0;
}