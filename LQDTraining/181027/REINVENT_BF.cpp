#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int oo = 1e9 + 7;

int n, m, x, spe[N], dist[N], res;
vector<int> adj[N];
queue<int> q;

void BFS(int s) {
	for (int i = 1; i <= n; ++ i) dist[i] = oo;
	while (!q.empty()) q.pop();

	dist[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				if (spe[v]) {
					res = min(res, dist[v]);
					// cerr << u << " -> " << v << " " << dist[v] << "\n";
					return;
				}
				q.push(v);
			}
 		}
	}
}

int main() {
	freopen("REINVENT.inp", "r", stdin);
	freopen("REINVENT.ans", "w", stdout);
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		int u;
		scanf("%d", &u);
		spe[u] = 1;
	}
	res = n;
	for (int i = 1; i <= n; ++ i) {
		if (spe[i]) BFS(i);
	}
	printf("%d", res);
}