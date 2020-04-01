#include <bits/stdc++.h>
using namespace std;

const int LOG = 22;
const int N = 1e5 + 5;

int n, v[N], cnt[N];
long long res;
vector<int> adj[N];

int getBit(int x, int i) {
	return (x & (1 << i)) > 0;
}

void dfs(int bit, int u, int par) {
	cnt[u] = (getBit(v[u], bit) == 0);
	int sum = 0;
	for (int v : adj[u]) {
		if (v == par) continue;
		if (cnt[u] == 0) 
			res -= (1LL << bit) * cnt[v] * (cnt[u] - 1);
		cnt[u] += cnt[v];
	}
}	

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &v[i]);
	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < LOG; ++ i) {
		res += 1LL * n * (n - 1) / 2 * (1 << i);
		dfs(i, 1, -1);
	}
	printf("%lld\n", res);
}