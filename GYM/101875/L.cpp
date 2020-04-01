#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, s, res;
vector<int> adj[N];

void dfs(int u, int par, int len) {
	res = max(res, len);
	for (int v : adj[u]) {
		if (v != par) {
			dfs(v, u, len + 1);
		}
	}
}

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(s, -1, 1);
	printf("%d\n", res);
}