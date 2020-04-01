#include <bits/stdc++.h>
using namespace std;

const int N = 1005, oo = 1e9 + 7;

int n, w[N], p[N], dp[N][N][2];
vector<int> adj[N];

// int calc(int bound, int u) {
// 	int ret = 0;
// 	for (int v : adj[u]) {
// 		ret += calc(bound, v);
// 	}
// 	if (w[u] <= bound) ret = max(ret, dp[u]);
// 	return ret;
// }

// void dfs(int u) {
// 	dp[u] = 1;
// 	for (int v : adj[u]) {
// 		dfs(v);
// 		dp[u] += calc(w[s], v);
// 	}
// 	res = max(res, dp[u]);
// }

void dfs(int s, int u) {
	if (s == u || w[s] > w[u]) dp[s][u][1] = 1;
	else dp[s][u][1] = -oo;
	dp[s][u][0] = 0;
	for (int v : adj[u]) {
		dfs(s, v);
		dp[s][u][1] += max(0, max(dp[u][v][1], dp[u][v][0]));
		dp[s][u][0] += max(0, max(dp[s][v][1], dp[s][v][0]));
	}
	// cerr << s << ' ' << u << ' ' << dp[s][u][0] << ' ' << dp[s][u][1] << '\n';
}

int main() {
	scanf("%d", &n);
	w[0] = oo;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d", &w[i], &p[i]);
		adj[p[i]].push_back(i);
	}
	for (int s = n; s >= 0; -- s) {
		dfs(s, s);
	}
	printf("%d\n", dp[0][0][0]);
}