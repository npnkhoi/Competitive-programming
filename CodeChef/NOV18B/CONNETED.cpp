#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<int> adj[N], tmp, ans[N];
int mark[N];

void dfs(int u) {
	mark[u] = 1;
	tmp.push_back(u);
	for (int v : adj[u]) {
		if (!mark[v]) dfs(v);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int p = 0;

	for (int i = 1; i <= n; ++ i) {
		if (mark[i]) continue;

		tmp.clear();
		dfs(i);
		if (tmp.size() == 1) {
			ans[0].push_back(i);
		} else {
			ans[++p] = tmp;
		}
	}

	int head = (ans[0].size() == 0);

	printf("%d\n", p - head + 1);
	for (int i = head; i <= p; ++ i) {
		sort(ans[i].begin(), ans[i].end());
		printf("%d\n", ans[i].size());
		for (int v : ans[i]) printf("%d ", v);
		printf("\n");
	}
}