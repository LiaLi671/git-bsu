#include <iostream>
#include<vector>
#include<fstream>
using namespace std;
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int s;
	in >> s;
	if (s == 0 or s == 1) {
		out << 0;
		return 0;
	}
	vector<vector<int>> M1(s, vector<int>(2));
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < 2; j++) {
			in>> M1[i][j];
		}
	}
	vector<vector<long long>> M2(s, vector<long long>(s,0));
	for (int i = 0; i < s - 1; i++) {
		M2[i][i + 1] = M1[i][0] * M1[i][1] * M1[i + 1][1];
	}
	long long r;
	for (int l = 0; l < s - 1; l++) {
		for (int i = 0; i < s - 1 - l; i++) {
			int j = i + 1 + l;
			long long min = 9223372036854775807;
			for (int k = i; k < j; k++) {
				r = M2[i][k] + M2[k + 1][j] + M1[i][0] * M1[k+1][0] * M1[j][1];
				if (r < min) {
					min = r;
				}
			}
			M2[i][j] = min;
		}
	}
	out << M2[0][s-1] << endl;




	/*for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			cout << M2[i][j] << " ";
		}
		cout << endl;
	}*/



	return 0;
}