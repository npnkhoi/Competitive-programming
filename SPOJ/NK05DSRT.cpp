#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const long long oo = 1e18 + 7;

int tc, n, m, c;
long long dist[N];
vector<pair<int, int>> adj[N];
priority_queue
	<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> heap;

long long cost(long long vol, int dist) {
	if (c >= vol + dist) return vol + dist;
	if (c <= 2*dist) return oo;

	long long firstPhase = vol - (c - dist);
	if (firstPhase % (c - 2 * dist)) 
		firstPhase += c - 2 * dist - firstPhase % (c - 2 * dist);
	return firstPhase / (c - 2 * dist) * c + (dist + vol - firstPhase);
}

int main() {
	// freopen("test.inp", "r", stdin);
	scanf("%d", &tc);
	// cerr << "tc =" << tc << '\n';
	while (tc --) {
		scanf("%d%d%d", &n, &m, &c);
		for (int i = 1; i <= n; ++ i) adj[i].clear();
		for (int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		for (int i = 1; i < n; ++i) dist[i] = oo;
		dist[n] = 0;
		while (!heap.empty()) heap.pop();
		heap.push({0, n});
		while (!heap.empty()) {
			long long l = heap.top().first;
			int u = heap.top().second;
			heap.pop();

			if (l > dist[u]) continue;

			for (auto v : adj[u]) {
				if (dist[v.first] > cost(l, v.second)) {
					dist[v.first] = cost(l, v.second);
					heap.push({dist[v.first], v.first});
				}
			}
		}
		printf("%lld\n", dist[1]);
		// for (int i = 1; i <= n; ++i) cerr << dist[i] << ' ';
		// cerr << '\n';
	}
}