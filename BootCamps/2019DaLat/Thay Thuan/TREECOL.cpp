#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int oo = 1e9 + 7;

int tc, n;
int f[N][N];
int leaf[N];
vector<int> adj[N];

void read(int &x) {
	char c;
	do c = getchar(); while (c < '0' || '9' < c);
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = 10 * x + c - '0';
	}
}

void dfs(int u, int par) {
	leaf[u] = 0;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == par) {
			// swap(adj[u][i], adj[u][0]);
			continue;
		}
		dfs(v, u);
		leaf[u] += leaf[v];
	}
	if (leaf[u] == 0) {
		leaf[u] = 1;
		f[u][0] = f[u][1] = 0;
		return;	
	}

	int s = 0, white = 0;
	for (int x = 1; x <= leaf[u]; ++x) f[u][x] = -oo;

	// for (int v : adj[u]) {
	for (int i = 0; i < adj[u].size(); ++ i) {
		int v = adj[u][i];
		// cerr << u << " -> " << v << "\n";
		if (v == par) continue;

		// for black-case
		s += leaf[v];
		for (int x = s; x >= 1; --x) {
			int bound2 = min(leaf[v], x);
			// x - y <= s - leaf[v] => y >= x - s + leaf[v]
			int bound1 = max(1, x - s + leaf[v]);
			for (int y = bound1; y <= bound2; ++ y) {
				f[u][x] = max(f[u][x], f[u][x - y] + f[v][y] + (x - y) * y);
			}
		}

		// for (int x = 1; x <= leaf[u]; ++x) g[x] = -oo;
		// for (int x = s; x >= 0; --x) {
		// 	for (int y = 0; y <= leaf[v] && y <= x; ++ y) {
		// 		g[x + y] = max(f[u][x+y], f[u][x] + f[v][y] + x * y);
		// 	}
		// }		
		// s += leaf[v];

		// for white-case
		int tmp = 0;
		for (int y = 1; y <= leaf[v]; ++ y) {
			tmp = max(tmp, y + f[v][y]);
		}
		white += tmp;
	}
	f[u][1] = max(f[u][1], white);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	read(tc);
	while (tc --) {
		read(n);
		for (int i = 1; i <= n; ++ i) {
			adj[i].clear();
		}
		for (int i = 1; i < n; ++ i) {
			int u, v;
			read(u); read(v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1, -1);
		int res = 0;
		for (int x = 1; x <= leaf[1]; ++ x) {
			res = max(res, f[1][x]);
		}
		// printf("%d\n", res);
		cout << res << '\n';
	}
}