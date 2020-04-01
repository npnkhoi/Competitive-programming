#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, b, s, t;
int mark[N];
vector<pair<int, pair<int, int>>> adj[N];
vector<int> node;

void dfs(int id, int u) {
	mark[u] = 1;
	for (auto v : adj[u]) {
		if (mark[v.first] == 1 || id < v.second.first || v.second.second < id) continue;
		dfs(id, v.first);
	}
} 

bool check(int id) {
	memset(mark, 0, sizeof mark);
	dfs(id, s);
	return mark[t];
} 

void Input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> b;
	cin >> s >> t;
	for (int i = 0; i < m; ++ i) {
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		adj[u].push_back({v, {l, r}});
		node.push_back(l);
		node.push_back(r);
	}
	sort(node.begin(), node.end());
	node.resize(unique(node.begin(), node.end()) - node.begin());
}

void Solve() {
	int res = 0;
	for (int i = 0; i < node.size(); ++ i) {
		if (check(node[i])) res ++;
		if (i != (int) node.size()-1 && node[i+1] - node[i] != 1) {
			if (check(node[i]+1)) {
				res += node[i+1] - node[i] - 1;
			}
		}
	}
	cout << res;
}

int main() {
	Input();
	Solve();
}