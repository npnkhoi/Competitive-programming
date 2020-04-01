#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, res;
int w[N], p[N], f[N], dp[N], up[N];
vector<int> adj[N], g[N];

void recalc(int u, int x) {
	sort(g[u].begin(), g[u].end(), [](int x, int y) {
		return w[x] < w[y];
	});
	while (!g[u].empty() && w[g[u].back()] > x) g[u].pop_back();
	int tmp = 0;
	for (int v : g[u]) {
		recalc(v, x);
		tmp += f[v];
	}
	f[u] = max(dp[u], tmp);
}

void dfs(int u) {
	for (int v : adj[u]) dfs(v);
	dp[u] = 1;
	for (int v : adj[u]) {
		if (w[v] > w[u]) {
			continue;
			// g[u].push_back(v);
		}
		recalc(v, w[u]);
		dp[u] += f[v];
		
	}
	res = max(res, dp[u]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d %d", &w[i], &p[i]);
		if (i != 1) adj[p[i]].push_back(i);
	}
	for (int i = 2; i <= n; ++ i) {
		up[i] = up2[i] = p[i];
		while (w[up[i]] >= w[i]) up[i] = up[up[i]];
		while (w[up2[i]] < w[i]) up2[i] = up2[up2[i]];
		if (up[i] != 0) {
			g[up[i]].push_back(i);
			// cerr << "g: " << up[i] << " -> " << i << '\n';
		}
		if (up2[i] != 0) {
			g2[up2[i]].push_back(i);
		}
		cerr << up[i] << ' ';
	}
	cerr << '\n';
	dfs(1);
	for (int i = 1; i <= n; ++ i) cerr << dp[i] << ' '; cerr << '\n';
	for (int i = 1; i <= n; ++ i) cerr << f[i] << ' '; cerr << '\n';
	printf("%d\n", res);
}