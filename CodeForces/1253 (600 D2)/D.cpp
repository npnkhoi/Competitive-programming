#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, l, r, mark[N], a[N];
vector<int> adj[N];
set<int> st;

void dfs(int u) {
	l = min(l, u);
	r = max(r, u);
	mark[u] = 1;
	for (int v : adj[u]) {
		if (mark[v] == 0) {
			dfs(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++ i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int res = 0, idx = 0;

	for (int i = 1; i <= n; ++i) {
		if (mark[i] != 0) continue;

		l = n + 1, r = 0;
		dfs(i);
		idx ++;
		// cerr << "done dfs: " << l << ' ' << r << '\n';
		if (l == r) a[i] = n + 1;
		else {
			a[l] = idx;
			a[r] = -idx;
		}
	}
	// for (int i = 1; i <= n; ++ i) {
	// 	cerr << a[i] << ' ';
	// }
	// cerr << '\n';

	for (int i = 1; i <= n; ++ i) {
		if (a[i] == 0) continue;
		if (a[i] == n + 1) res += !st.empty();
		else if (a[i] > 0) {
			res += !st.empty();
			st.insert(a[i]);
		} else {
			st.erase(-a[i]);
		}
	}
	cout << res;
}