#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int tc, n, m, cLib, cRoad, cnt;
int mark[N];
vector<int> adj[N];

void dfs(int u) {
	mark[u] = 1;
	for (int v : adj[u]) {
		if (mark[v]) continue;
		dfs(v);
	}
}

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d%d", &n, &m, &cLib, &cRoad);
		for (int i = 1; i <= n; ++ i) adj[i].clear();
		for (int i = 1; i <= m; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(mark, 0, sizeof mark);
		long long res = 0;
		cnt = 0;
		for (int i = 1; i <= n; ++ i) {
			if (!mark[i]) {
				cnt ++;
				dfs(i);
			}
		}
		res = 1LL * cnt * cLib + 1LL * (n - cnt) * min(cLib, cRoad);
		printf("%lld\n", res);
	}
}