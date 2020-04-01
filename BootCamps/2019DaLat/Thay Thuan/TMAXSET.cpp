#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int tc, n, m, q, a[N], mark[N], f[N][2];
vector<int> adj[N];

void dfs(int u, int par) {
	// cerr << "dfs " << u << "\n";
	f[u][0] = 0;
	f[u][1] = (mark[u] ? a[u] : 0);
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v, u);
		f[u][0] += max(f[v][0], f[v][1]);
		f[u][1] += f[v][0];
	}
}

int main() {
	// freopen("TMAXSET.inp", "r", stdin);
	// freopen("TMAXSET.out", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++ i) {
			adj[i].clear();
		}
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= m; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		scanf("%d", &q);
		while (q --) {
			int k;
			scanf("%d", &k);
			memset(mark, 0, sizeof mark);
			int u;
			for (int i = 1; i <= k; ++ i) {
				scanf("%d", &u);
				mark[u] = 1;
			}
			// memset(f, 0, sizeof f);
			dfs(0, -1);
			printf("%d\n", max(f[0][0], f[0][1]));
		}
		printf("\n");
	}
}