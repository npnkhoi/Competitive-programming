#include <bits/stdc++.h>
using namespaces std;

void dfs(int u) {
	mark[u] = 1;
	for (auto son : adj[u]) {
		if (mark[vtx]) continue;

		dep[vtx] = dep[u] + 1;
		len_up[vtx][0] = son.second;
		anc[vtx][0] = u;
		for (int lev = 1; (1 << lev) <= dep[vtx]; ++ lev) {
			len_up[vtx][lev] = len_up[vtx][lev-1] + len_up[anc[vtx][lev-1]][lev-1];
			anc[vtx][lev] = anc[anc[vtx][lev-1]][lev-1];
		}
	}
}

int main() {
	// input
	cin >> n >> q;
	int u, v, d;
	for (int i = 0; i < n - 1; ++i) {
		cin >> u >> v >> d;
		adj[u].push_back({v, d});
		adj[v].push_back({u, d});
	}

	dfs(1);
	int f, s, t;
	while (q--) {
		cin >> s >> f >> t;

	} 
}