#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, dep[N];
vector<int> adj[N];

void dfs(int u, int par) {
	for (int v : adj[u]) {
		if (v == par) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}

int dist(int u, int v) {
	memset(dep, 0, sizeof dep);
	dfs(u, -1);
	return dep[v];
}

int main() {
	freopen("PIGS.inp", "r", stdin);
	freopen("PIGS.ans", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int res = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = i + 1; j <= n; ++ j) {
			for (int k = j + 1; k <= n; ++ k) {
				int x = dist(i, j), y = dist(j, k), z = dist(k, i);
				if (x == y && y == z) {
					res ++;
					// cerr << i << " " << j << " " << k << "\n";
				}
			}
		}
	}
	printf("%d\n", res);
}