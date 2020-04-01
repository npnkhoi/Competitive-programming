#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, a, b, nxt[N], pre[N], res, mark[N], f[N];
vector<int> adj[N], roots, data[N];

void findPath(int u, int par) {
	if (u == b) {
		mark[u] = 1;
		roots.push_back(u);
		return;
	}
	for (int v : adj[u]) {
		if (v == par) continue;
		findPath(v, u);
		if (mark[v]) {
			mark[u] = 1;
			roots.push_back(u);
			nxt[u] = v;
			pre[v] = u;
			return;
		}
	}
}

void dfs(int u, int par) {
	for (int v : adj[u]) {
		if (v == par || mark[v]) continue;
		dfs(v, u);
		data[u].push_back(f[v]);
	}
	sort(data[u].rbegin(), data[u].rend());
	// cerr << "data " << u << ".size() = " << data[u].size() << "\n";
	for (int i = 0; i < data[u].size(); ++ i) {
		f[u] = max(f[u], i + 1 + data[u][i]);
		// cerr << data[u][i] << " ";
	}
	// cerr << "\n";
}

int main() {
	scanf("%d%d%d",	&n, &a, &b);
	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	findPath(a, -1);
	// for (int i = 1; i <= n; ++ i) cerr << mark[i] << " "; cerr << "\n";
	for (int u : roots) {
		dfs(u, -1);
		// cerr << u << " ";
	}
	// cerr << "\n";
	int tmp = 0;
	// for (int i = 1; i <= n; ++ i) cerr << f[i] << " "; cerr << "\n";
	while (1) {
		// cerr << f[a] << " " << f[b] << "\n";
		res = max(res, max(f[a], f[b]) + tmp);
		if (nxt[a] == b || pre[b] == a) break;
		a = nxt[a]; b = pre[b];
		tmp ++;
	}
	printf("%d\n", res);
}