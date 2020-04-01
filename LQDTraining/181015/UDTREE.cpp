#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k;
vector<int> adj[N];
int ret[N], noRet[N], topLeaf[N], dep[N];

void dfs(int u) {
	topLeaf[u] = n + 1;
	int tmpNoRet = - (n + 1);

	if (adj[u].empty()) {
		noRet[u] = ret[u] = 1;
		topLeaf[u] = dep[u];
		return;
	}

	for (int i = 0; i < adj[u].size(); ++ i) {
		int v = adj[u][i];

		dep[v] = dep[u] + 1;
		dfs(v);

		noRet[u] += ret[v];
		tmpNoRet = max(tmpNoRet, noRet[v] - ret[v]);
		ret[u] += ret[v];
		topLeaf[u] = min(topLeaf[u], topLeaf[v]);
	}
	noRet[u] += tmpNoRet;
	if (topLeaf[u] - dep[u] >= k) ret[u] = 0;
}

int main() {
	freopen("UDTREE.inp", "r", stdin);
	freopen("UDTREE.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 2; i <= n; ++ i) {
		int par;
		scanf("%d", &par);
		adj[par].push_back(i);
	}
	dep[1] = 0;
	dfs(1);
	// for (int i = 1; i <= n; ++ i) {
	// 	cerr << dep[i] << " " << ret[i] << " " << noRet[i] << " " << topLeaf[i] << "\n";
	// }
	printf("%d", noRet[1]);
}