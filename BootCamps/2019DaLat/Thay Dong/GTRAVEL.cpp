#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, dep[N], degIn[N], degOut[N];
long long res;
vector<int> adj[N];

void dfs(int u) {
	for (int v : adj[u]) {
		if (dep[v] == 0) {
			dep[v] = dep[u] + 1;
			dfs(v);
		} else {
			if (dep[v] - dep[u] == 2) {
				res --;
				// cerr << u << " " << v << "\n";
			} else if (par[v] == par[u]) {
				res --;
			}
		}
	}
}

int main() {
	freopen("GTRAVEL.inp", "r", stdin);
	freopen("GTRAVEL.out", "w", stdout);
	scanf("%d%d", &n, &m);
	// for (int i = 1; i <= n; ++ i) adj[0].push_back(i);
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		res += (v - u - 1);
		adj[u].push_back(v);
		degIn[v] ++;
		degOut[u] ++;
	}
	for (int u = 1; u <= n; ++ u) res += 1LL * degIn[u] * degOut[u];
	// cerr << res << "\n";
	// dep[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		if (dep[i] == 0) {
			dep[i] = 1;
			dfs(i);
		}
	}
	// res = 1LL * n * (n - 1) * (n - 2) / 6;
	printf("%d\n", res);
}