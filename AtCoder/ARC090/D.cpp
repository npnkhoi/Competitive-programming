#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
typedef pair<int, int> ii;
const int N = 1e5 + 5;
const int M = 2e5 + 5;
int n, m;
int l[M], r[M], d[M], mark[N];
long long sum[N];
vector<ii> adj[N];

void dfs(int u) {
	mark[u] = 1;
	for (ii v : adj[u]) {
		if (!mark[v.fi]) {
			sum[v.fi] = sum[u] + v.se;
			dfs(v.fi);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d%d", &l[i], &r[i], &d[i]);
		adj[l[i]].push_back(mp(r[i], d[i]));
		adj[r[i]].push_back(mp(l[i], -d[i]));
	}
	for (int u = 1; u <= n; u ++) {
		if (mark[u] == 0) {
			dfs(u);
		}
	}
	for (int i = 1; i <= m; i ++) {
		if (sum[r[i]] - sum[l[i]] != d[i]) {
			printf("No\n");
			exit(0);
		}
	}
	printf("Yes\n");
}