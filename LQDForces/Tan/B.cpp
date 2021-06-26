#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> Distance;
typedef pair<Distance, int> DPack;
const int N = 1e5 + 5;
const long long INF = 1e18;

int n, m, k;
vector<pair<int, int>> adj[N];
Distance dist[N];
priority_queue<DPack, vector<DPack>, greater<DPack>> heap;

void dijsktra() {
	for (int i = 1; i <= n; ++ i) {
		dist[i] = {INF, k+1};
	}
	dist[1] = {0, 1};
	heap.push({{0, 1}, 1});

	while (!heap.empty()) {
		DPack pivot = heap.top();
		heap.pop();
		
		int u = pivot.second;
		long long old_dist = pivot.first.first;
		int steps = pivot.first.second;

		for (auto edge : adj[u]) {
			int v = edge.second;
			// cerr << "Considering " << u << ' ' << v << '\n'; 
			long long new_dist = old_dist + edge.first;
			if (new_dist < dist[v].first || (new_dist == dist[v].first && steps + 1 < dist[v].second)) {
				dist[v] = {new_dist, steps + 1};
				heap.push({{new_dist, steps + 1}, v});
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++ i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}
	dijsktra();
	// for (int i = 1; i <= n; ++ i) { 
	// 	cerr << dist[i].first << ' ' << dist[i].second << '\n';
	// }
	cout << dist[n].first << ' ' << (dist[n].second <= k ? "YES" : "NO");
}