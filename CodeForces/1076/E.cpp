#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int N = 3e5 + 5;

int n, m;
vector<int> adj[N];
int dep[N];
long long ft[N], ans[N];
vector<ii> query[N];

void update(int i, int val) {
	for (; i <= n; i += i&-i) ft[i] += val;
}

long long get(int i) {
	long long res= 0;
	for (; i; i -= i & -i) res += ft[i];
	return res;
}

void dfs(int u, int par) {
	// cerr << "dfs " << u << "\n";
	for (ii t : query[u]) {
		update(dep[u], t.second);
		update(dep[u] + t.first + 1, - t.second);
	}
	ans[u] = get(dep[u]);
	for (int v : adj[u]) {
		if (v == par) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
	for (ii t : query[u]) {
		update(dep[u], - t.second);
		update(dep[u] + t.first + 1, + t.second);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++ i) {
		int v, d, x;
		scanf("%d%d%d", &v, &d, &x);
		query[v].push_back(make_pair(d, x));
	}
	dep[1] = 1;
	dfs(1, -1);
	for (int i = 1; i <= n; ++ i) printf("%lld ", ans[i]);
}