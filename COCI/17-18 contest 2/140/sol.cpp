#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int N = 3e5 + 5;
const int md = 1e9 + 7;
const int LOG = 19;

int n, m, res;
int dep[N], anc[N][LOG + 2], col[N], hi[N];
vector<int> adj[N], topo;
vector<ii> g[N];

void dfsInit(int u, int par) {
	// leaf[u] = 1;
	for (int i = 1; (1 << i) <= dep[u]; ++ i) {
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	}
	for (int v : adj[u]) {
		if (v == par) continue;
		// leaf[u] = 0;
		dep[v] = dep[u] + 1;
		anc[v][0] = u;
		dfsInit(v, u);
	}
	topo.push_back(u);
}

int LCA(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = LOG; i >= 0; -- i) {
		if (dep[v] - (1 << i) >= dep[u])
			v = anc[v][i];
	}
	if (u == v) return u;
	for (int i = LOG; i >= 0; -- i) {
		if ((1 << i) <= dep[u] && anc[u][i] != anc[v][i]) {
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	return anc[u][0];
}

void coloring(int u, int par) {
	for (ii v : g[u]) {
		if (v.first	== par) continue;
		if (col[v.first] == -1) {
			col[v.first] = col[u] ^ v.second;
			coloring(v.first, u);
		} else {
			if (col[v.first] != col[u] ^ v.second) {
				res = 0;
			}
		}
	}
}

int main() {
	freopen("sol.inp", "r", stdin);
	freopen("sol.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfsInit(1, -1);
	for (int i = 1; i <= n; ++ i) 
		hi[i] = dep[i];
	for (int i = 1; i <= m; ++ i) {
		int u, v, t;
		scanf("%d%d", &u, &v);
		t = LCA(u, v);
		hi[u] = min(hi[u], dep[t]);
		hi[v] = min(hi[v], dep[t]);
		if (t != u && t != v) {
			g[u].push_back(make_pair(v, 1));
			g[v].push_back(make_pair(u, 1));
		}
	}
	for (int u : topo) {
		if (u == 1) continue;
		hi[anc[u][0]] = min(hi[anc[u][0]], hi[u]);
		if (dep[u] - hi[u] >= 2) {
			g[anc[u][0]].push_back(make_pair(u, 0));
			g[u].push_back(make_pair(anc[u][0], 0));
		} 
	}
	res = 1;
	memset(col, -1, sizeof col);
	for (int i = 1; i <= n; ++ i) {
		if (i == 1) continue;
		if (col[i] == -1) {
			res = 2 * res % md;
			col[i] = 0;
			coloring(i, -1);
		}
	}
	printf("%d\n", res);
}