#include <bits/stdc++.h>
using namespace std;

const int N = 15e3 + 5;

int n, m, deg[N];
string exercise[N];
map<string, int> id;
vector<int> adj[N], ans;
set<int> ready;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> exercise[i];
		id[exercise[i]] = i;
	}
	string ex1, ex2;
	for (int i = 0; i < m; ++i) {
		cin >> ex1 >> ex2;
		adj[id[ex2]].push_back(id[ex1]);
		deg[id[ex1]] ++;
	}
	for (int i = 0; i < n; ++i) {
		if (deg[i] == 0) {
			ready.insert(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ready.empty()) {
			cout << "You should take care of it later.\n";
			return 0;
		} else {
			int nxt = *ready.begin();
			ans.push_back(nxt);
			ready.erase(ready.begin());
			for (int u : adj[nxt]) {
				deg[u] --;
				if (deg[u] == 0) {
					ready.insert(u);
				}
			}
		}
	}
	for (int idx : ans) cout << exercise[idx] << " ";	
}