#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, k, dist[N];
queue<int> q;
vector<int> adj[N];

int main() {
	scanf("%d%d%d",	&n, &m, &k);
	memset(dist, -1, sizeof dist);
	for (int i = 1; i <= k; ++ i) {
		int u;
		scanf("%d", &u);
		q.push(u);
		dist[u] = 0;
	}
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[v].push_back(u);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; ++ i) printf("%d\n", dist[i]);
}