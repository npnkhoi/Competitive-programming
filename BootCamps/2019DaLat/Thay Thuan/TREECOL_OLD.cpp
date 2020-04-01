#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int oo = 1e9 + 7;

int tc, n;
int f[N][N][2], g[N][N][2];
int leaf[N];
vector<int> adj[N], child[N];

void dfs(int u, int par) {
	leaf[u] = 0;
	for (int v : adj[u]) {
		if (v == par) continue;
		dfs(v, u);
		child[u].push_back(v);
		leaf[u] += leaf[v];
	}
	for (int j = 1; j <= n; ++ j) f[u][j][0] = f[u][j][1] = - oo;
	if (leaf[u] == 0) {
		leaf[u] = 1;
		return;	
	}
	int nChild = child[u].size();
	int nLeaf = leaf[u];

	// memset
	for (int j = 1; j <= nLeaf; ++ j) {
			g[0][j][0] = g[0][j][1] = -oo;
	}

	// calc f[u][top][0]
	for (int i = 1; i <= nChild; ++ i) {
		int v = child[u][i - 1];
		for (int j = 1; j <= nLeaf; ++ j) {
			g[i][j][0] = g[i][j][1] = - oo;
			for (int x = 0; x <= leaf[v]; ++ x) {
				g[i][j][0] = max(g[i][j][0], f[v][x][0] + 1 + g[i-1][j-1][0]);
				g[i][j][1] = max(g[i][j][1], f[v][x][0] + j - 1 + g[i-1][j-1][1]);
			}
			int tmp = min(j, leaf[v]);
			for (int x =  0; x <= min(j, tmp); ++ x) {
				g[i][j][0] = max(g[i][j][0], f[v][x][1] + x + g[i-1][j - x][0]);
				g[i][j][1] = max(g[i][j][1], f[v][x][1] + x * (j - x) + g[i-1][j - x][1]);
			}
		}
	}
	for (int j = 1; j <= nLeaf; ++ j) {
		f[u][j][0] = g[nChild][j][0];
		f[u][j][1] = g[nChild][j][1];
	}
}

int main() {
	// freopen("TREECOL.inp", "r", stdin);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			adj[i].clear();
			child[i].clear();
		}
		for (int i = 1; i < n; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1, -1);
		int res = 0;
		for (int x = 0; x <= leaf[1]; ++ x) {
			res = max(res, max(f[1][x][0], f[1][x][1]));
		}
		printf("%d\n", res);
	}
}