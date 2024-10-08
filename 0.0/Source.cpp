#include <iostream>
#include <fstream>
#include <set>
using namespace std;
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	set <int> Mas;
	int el;
	long long sum = 0;
	while (in) {
		in >> el;
		Mas.insert(el);
	}
	for (set<int>::const_iterator it = Mas.begin(); it != Mas.end(); it++) {
		sum += (*it);
	}
	out << sum;
	return 0;

}