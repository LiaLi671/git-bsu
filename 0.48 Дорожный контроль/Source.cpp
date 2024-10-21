#include <iostream>
#include <vector>
#include<fstream>
#include <algorithm>
#include<stack>

using namespace std;
vector<int> with;
vector<int> without;
vector<bool> visited;
vector <vector <int>> G;
stack<int> s;
stack<int> res;
vector<int> parent_int;
vector<bool> vis;
void func(int a) {
	visited[a] = true;
	s.push(a);

	while (!s.empty()) {
		int u = s.top();
		s.pop();
		res.push(u);
		with[u] = 1;
		without[u] = 0;
		for (int v : G[u]) {
			if (!visited[v]) {
				parent_int[v] = u;
				visited[v] = true;
				s.push(v);
			}
		}
	}
	while(!res.empty()) {
		int u = res.top();
		res.pop();
		for (int v : G[u]) {
			if (v != parent_int[u] and !vis[v]) {
				without[u] += max(with[v], without[v]);
				with[u] += without[v];
				vis[v] = true;
			}
			
		}
	}
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, k, el;
	in >> n;
	if (n == 1) {
		in >> k;
		out << 0;
		return 0;
	}
	G.resize(n);
	with.resize(n);
	without.resize(n);
	visited.resize(n, false);
	vis.resize(n, false);
	parent_int.resize(n, -1);
	for (int i = 0; i < n; i++) {
		in >> k;
		for (int j = 0; j < k; j++) {
			in >> el;
			G[i].push_back(el - 1);
			G[el - 1].push_back(i);
		}
	}
	func(0);
	/*while (!res.empty()) {
		out << res.top() << " ";
		res.pop();
	}
	out << endl;*/
	int result = n - max(with[0], without[0]);
	out << result;
	return 0;
}