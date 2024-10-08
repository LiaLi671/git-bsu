#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	string s ="";
	getline(in, s);
	if (s.size() == 0) {
		out << 0 << endl;
	} else if (s.size() == 1) {
		out << 1 << endl;
		out << s << endl;

	} 
	else if (s.size() > 1) {
		vector<vector <int>> M(s.size(), vector<int>(s.size()));
		for (int i = 0; i < s.size(); i++) {
			M[i][i] = 1;
		}
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == s[i + 1]) {
				M[i][i + 1] = 2;
			}
			else {
				M[i][i + 1] = 1;
			}
		}
		for (int k = 0; k < s.size() - 2; k++) {
			for (int i = 0; i < s.size() - 2 - k; i++) {
				int j = i + 2 + k;
				if (s[i] == s[j]) {
					M[i][j] = M[i + 1][j - 1] + 2;
				}
				else {
					M[i][j] = max(M[i][j - 1], M[i + 1][j]);
				}
			}
		}
		/*for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				cout << M[i][j] << " ";
			}
			cout << endl;
		}*/
		out << M[0][s.size() - 1] << endl;
		if (M[0][s.size() - 1] == 1) {
			out << s[0] << endl;
			return 0;
		}
		vector<string> res(M[0][s.size() - 1]);
		int i = 0, j = s.size() - 1;
		int index = 0;
		while (M[i][j] != 0) {
			if (s[i] == s[j]) {
				res[index] = s[i];
				i++;
				j--;
				index++;
			}
			else {
				if (M[i + 1][j] == M[i][j]) {
					i++;
				}
				else if (M[i][j - 1] == M[i][j]) {
					j--;
				}
			}
		}
		for (int i = 0; i < res.size() / 2; i++) {
			out << res[i];
		}
		for (int i = res.size() - 1; i >= 0; i--) {
			out << res[i];
		}
	}
	return 0;
}