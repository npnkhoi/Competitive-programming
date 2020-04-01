#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;

int tc, m, n, s, d;
vector<int> adj[N][2];

int dist[N];
queue<int> q;

void Push(int d, int u) {
	q.push(u);
	dist[u] = d;
	for (int v : adj[u][0]) {
		if (d < dist[v]) {
			Push(d, v);
		}
	}
}

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &n, &m);
		for (int u = 1; u <= n; ++ u) {
			adj[u][0].clear();
			adj[u][1].clear();
		}
		for (int i = 1; i <= m; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u][0].push_back(v);
			adj[v][1].push_back(u);
		}
		scanf("%d%d", &s, &d);

		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; ++ i) {
			dist[i] = oo;
		}

		Push(0, s);
		dist[s] = 0;

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : adj[u][1]) {
				if (dist[u] + 1 < dist[v]) {
					dist[v] = dist[u] + 1;
					if (v == d) break;
					Push(dist[v], v);
				}
			}
		}
		printf("%d\n", (dist[d] == oo ? -1 : dist[d]));
	}
}