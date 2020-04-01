#include <bits/stdc++.h>
using namespace std;

const int N = 105, oo = 1e9 + 7;

int tc, n, m, c;
int d[N][N], dist[N];
priority_queue
	<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

int cost(int vol, int dist) {
	if (c >= vol + dist) return vol + dist;
	if (c <= 2*dist) return oo;

	int firstPhase = vol - (c - dist);
	if (firstPhase % (c - 2 * dist)) 
		firstPhase += c - 2 * dist - firstPhase % (c - 2 * dist);
	return firstPhase / (c - 2 * dist) * c + (dist + vol - firstPhase);
}

int main() {
	freopen("test.inp", "r", stdin);
	scanf("%d", &tc);
	// cerr << "tc =" << tc << '\n';
	while (tc --) {
		scanf("%d%d%d", &n, &m, &c);
		for (int i = 1; i <= n; ++ i) {
			for (int j = i + 1; j <= n; ++ j) {
				d[i][j] = d[j][i] = oo;
			}
		}
		for (int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
			d[u][v] = d[v][u] = min(d[u][v], w);
		}
		for (int mid = 1; mid <= n; ++mid) {
			for (int u = 1; u <= n; ++u) {
				for (int v = 1; v <= n; ++v) {
					d[u][v] = min(d[u][v], d[u][mid] + d[mid][v]);
				}
			}
		}
		for (int i = 1; i < n; ++i) dist[i] = oo;
		dist[n] = 0;
		while (!heap.empty()) heap.pop();
		heap.push({0, n});
		while (!heap.empty()) {
			int l = heap.top().first, u = heap.top().second;
			heap.pop();

			if (l > dist[u]) continue;

			for (int v = 1; v <= n; ++v) {
				if (d[u][v] == oo) continue;
				if (dist[v] > cost(l, d[u][v])) {
					dist[v] = cost(l, d[u][v]);
					heap.push({dist[v], v});
				}
			}
		}
		printf("%d\n", dist[1]);
		// for (int i = 1; i <= n; ++i) cerr << dist[i] << ' ';
		// cerr << '\n';
	}
}