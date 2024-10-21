#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
int main() {
	ifstream in("bst.in");
	ofstream out("bst.out");
	int n;
	in >> n;
	vector<long long> data(n);
	vector<string> storona(n);
	vector<int> str(n);
	in >> data[0];
	storona[0] = "-";
	str[0] = -1;
	for (int i = 1; i < n; i++) {
		in >> data[i];
		in >> str[i];
		in >> storona[i];
	}
	vector<vector<long long>> PR(2, vector<long long>(n)); //сверху левая граница, снизу правая
	PR[0][0] = -9223372036854775806;
	PR[1][0] = 9223372036854775806;
	for (int i = 1; i < n; i++) {	//если (, то -1, если [,то все норм
		if (storona[i] == "L") {
			PR[0][i] = PR[0][str[i]-1];
			PR[1][i] = data[str[i]-1]-1;
		}
		else if (storona[i] == "R") {
			PR[0][i] = data[str[i] - 1];
			PR[1][i] = PR[1][str[i]-1];
		}
		if (data[i] < PR[0][i] or data[i] > PR[1][i]) {
			out << "NO";
			return 0;
		}
	}
	out << "YES";
	return 0;
}