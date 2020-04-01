#include <bits/stdc++.h>
using namespace std;

const int N = 405;
const int oo = 1e9 + 7;

int tc, m, n;
int link[N][N], f[N][N], dist[N], d, maxAdj;
queue<int> q;
vector<int> adj[N], layer[N];

void getInt(int &x) {
	int c = getchar();
	while (c < '0' || '9' < c) c = getchar();
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = x * 10 + c - '0';
	}
}

void input() {
	getInt(n); getInt(m);
	for (int i = 1; i <= n; ++ i) adj[i].clear();
	memset(link, 0, sizeof link);
	for (int i = 1; i <= n; ++ i) link[i][i] = 1;
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		getInt(u); getInt(v);
		u ++; v ++;
		// cerr << u << " - " << v << "\n";
		if (link[u][v] || u == v) continue;
		adj[u].push_back(v);
		adj[v].push_back(u);
		link[u][v] = link[v][u] = 1;
	}
}

void bfs() { // calc dist[], layer{}
	for (int i = 1; i <= n; ++ i) dist[i] = oo;
	for (int i = 1; i <= n; ++ i) layer[i].clear();
	memset(f, 0, sizeof f);

	dist[1] = 0;
	layer[0].push_back(1);
	q.push(1);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (dist[v] == oo) {
				dist[v] = dist[u] + 1;
				layer[dist[v]].push_back(v);
				q.push(v);
			}
		}
	}
}

void dp() {
	d = dist[2] - 1;
	maxAdj = 0;
	if (d == 0) {
		maxAdj = adj[1].size();
		return;
	}
	// -----------------------------------
	memset(f, 0, sizeof f);  
	for (int u : layer[1]) {
		f[u][1] = adj[1].size() - 1;
		for (int v : adj[u]) {
			if (!link[1][v]) f[u][1] ++;
		}
	}
	vector<int> pre, suf;
	for (int i = 1; i <= d - 1; ++ i) {
		for (int mid : layer[i]) {
			pre.clear(); suf.clear();
			for (int v : adj[mid]) {
				if (dist[v] < dist[mid]) {
					pre.push_back(v);
				} else if (dist[v] > dist[mid]) suf.push_back(v);
			}
			for (int x : pre) for (int y : suf) {
				int tmp = f[mid][x] - 1;
				for (int v : adj[y]) {
					if (!link[v][x] && !link[v][mid]) tmp ++;
				}
				f[y][mid] = max(f[y][mid], tmp);
			}
		}
	}
	for (int u : layer[d]) {
		if (link[u][2]) {
			for (int v : adj[u]) {
				if (dist[v] < dist[u]) maxAdj = max(maxAdj, f[u][v]);
			}
		}
	}
	// for (int i = 1; i <= d; ++ i) {
	// 	for (int u : layer[i]) {
	// 		for (int v : adj[u]) {
	// 			if (dist[v] < dist[u]) {
	// 				cerr << u << " " << v << " " << f[u][v] << "\n";
	// 			}
	// 		}
	// 	}
	// }
}

void answer(int test) {
	printf("Case #%d: %d %d\n", test, d, maxAdj);
}

int main() {
	// freopen("test.inp", "r", stdin);
	// freopen("test.out", "w", stdout);
	getInt(tc);
	for (int iTest = 1; iTest <= tc; iTest ++) {
		input();
		bfs();
		dp();
		answer(iTest);
	}
}