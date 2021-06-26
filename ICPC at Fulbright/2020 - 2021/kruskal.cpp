#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
const int M = N * (N+1) / 2;

pair<int, pair<int, int>> edgeList[M];
// [{r, {u, v}}, ...]
int n, m, start, parent[N], sz[N], result;

int find_root(int u) {
	while (u != parent[u]) {
		u = parent[u];
	}
	return u;
}

void unite(int u, int v, int r) {
	u = find_root(u);
	v = find_root(v);
	if (u == v) {
		return;
	}

	result += r;
	if (sz[u] < sz[v]) swap(u, v);
	parent[v] = u;
	sz[u] += sz[v];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++ i) {
		int u, v, r;
		cin >> u >> v >> r;
		edgeList[i] = {r, {u, v}};
	}
	cin >> start;

	// kruskal
	for (int i = 1; i <= n; ++ i) {
		parent[i] = i;
		sz[i] = 1;
	}

	sort(edgeList, edgeList + m);

	for (auto edge : edgeList) {
		int u = edge.second.first;
		int v = edge.second.second;
		int r = edge.first;

		unite(u, v, r);
	}

	cout << result;
}