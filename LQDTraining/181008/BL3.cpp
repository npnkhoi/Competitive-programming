#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, counter, res;
int num[N], low[N], art[N];
vector<int> adj[N];

void dfs(int u, int par, int isRoot) {
	// cerr << "dfs " << u << "\n";
	num[u] = low[u] = ++ counter;
	int cntSubTree = 0;
	for (int i = 0; i < (int) adj[u].size(); ++ i) {
		int v = adj[u][i];
		if (v == par) continue;
		if (num[v] == 0) {
			dfs(v, u, 0);
			low[u] = min(low[u], low[v]);

			if (low[v] >= num[u]) {
				cntSubTree ++;
			}
		} else {
			low[u] = min(low[u], num[v]);
		}
	}
	art[u] = cntSubTree - isRoot > 0;
}

int main() {
	freopen("BL3.inp", "r", stdin);
	freopen("BL3.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1, 1);
	// for (int i = 1; i <=
	for (int i = 1; i <= n; ++ i) {
		res += !art[i];
	}
	printf("%d", res);
}