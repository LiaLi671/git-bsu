#include <iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	vector <vector <int>> M(n+1, vector <int>(n+1));
	for (int i = 0; i <=n; i++) {
		M[i][0] = 0;
		M[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i-1] == B[j-1]) {
				M[i][j] = M[i - 1][j - 1] + 1;
			}
			else {
				M[i][j] = max(M[i - 1][j], M[i][j - 1]);
			}
		}
	}
	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << M[n][n] << endl;
	vector <int> resultA(M[n][n]);
	vector <int> resultB(M[n][n]);
	int i = n, j = n;
	int index = 0;
	int secIndex = 0;
	while (M[i][j] != 0) {
		if (A[i-1] == B[j-1]) {
			resultA[index]=i-1;
			resultB[secIndex]=(j-1);
			i--;
			j--;
			secIndex++;
			index++;
		}
		else {
			if (M[i-1][j] == M[i][j]) {
				i--;
			}
			else if (M[i][j-1] == M[i][j]) {
				j--;
			}
		}
	}
	for (int i = resultA.size()-1; i >=0; i--) {
		cout << resultA[i] << " ";
	}
	cout << endl;
	for (int i =resultA.size() - 1; i >= 0; i--) {
		cout << resultB[i] << " ";
	}
	return 0;
}