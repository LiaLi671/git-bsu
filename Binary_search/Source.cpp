#include <iostream>
using namespace std;
int bolshe(int* M, int end, int element) {
	int start = 0, middle;
	while (start < end) {
		middle = (start + end) / 2;
		if (M[middle] <= element) {
			start = middle + 1;
		}
		else {	// M[middle] > element
			end = middle;
		}
	}
	return start;
}
int bolshe_ravno(int* M,int end, int element) {
	int start = 0, middle;
	while (start < end) {
		middle = (start + end) / 2;
		if (M[middle] < element) {
			start = middle + 1;
		}
		else {	// M[middle] >= element
			end = middle;
		}
	}
	return start;
}
int exist(int* M, int end, int element) {
	int start = 0, middle, find = 0;
	while (start <= end) {
		int middle = (start + end) / 2;
		if (element < M[middle]) {
			end = middle - 1;
		}
		else if (element > M[middle]) {
			start = middle +1;
		}
		else if (element == M[middle]) {
			find = 1;
			break;
		}
	}
	return find;
}


int main() {
	int n, k;
	cin >> n;
	int* M = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> M[i];
	}
	cin >> k;
	int* Zapros = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> Zapros[i];
	}

	int** Result = new int* [k];
	for (int i = 0; i < k; i++) {
		Result[i] = new int[3];
	}

	for (int i = 0; i < k; i++) {
		Result[i][0] = exist(M, n-1, Zapros[i]);
		Result[i][1] = bolshe_ravno(M, n, Zapros[i]);
		Result[i][2] = bolshe(M, n, Zapros[i]);
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 3; j++) {
			cout << Result[i][j] << " ";
		}
		cout << endl;
	}
	
	delete[]M;
	delete[]Zapros;

	for (int i = 0; i < k; i++)
		delete[] Result[i];
	delete[] Result;

	return 0;
}