#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<long long, ii> Pack;

const int N = 1e3 + 5;
const int MASK = (1 << 10) + 5;
const long long oo = 1e18 + 7;

int n, m, k;
int goods[N];
long long dist[N][MASK];
vector<ii> adj[N];
priority_queue<Pack, vector<Pack>, greater<Pack> > heap;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++ i) {
		int t, x;
		scanf("%d", &t);
		while (t --) {
			scanf("%d", &x);
			goods[i] |= (1 << (x - 1));
		}
	}
	for (int i = 1; i <= m; ++ i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}
	for (int i = 1; i <= n; ++ i) {
		for (int mask = 0; mask < (1 << k); ++ mask) {
			dist[i][mask] = oo;
		}
	}
	dist[1][goods[1]] = 0;
	heap.push(make_pair(0, make_pair(1, goods[1])));
	while (!heap.empty()) {
		Pack t = heap.top();
		heap.pop();

		if (t.first != dist[t.second.first][t.second.second]) continue;

		for (ii v : adj[t.second.first]) {
			if (t.first + v.second < dist[v.first][t.second.second | goods[v.first]]) {
				dist[v.first][t.second.second | goods[v.first]] = t.first + v.second;
				heap.push(make_pair(dist[v.first][t.second.second | goods[v.first]], 
					make_pair(v.first, t.second.second | goods[v.first])));
			}
		}
	}

	// for (int i = 1; i <= n; ++ i) {
	// 	for (int j = 0; j < (1 << k); ++ j) {
	// 		cerr << i << " " << j << " " << dist[i][j] << "\n";
	// 	}
	// }

	long long res = oo;
	for (int i = 0; i < (1 << k); ++ i) {
		for (int j = 0; j < (1 << k); ++ j) {
			if ((i | j) != (1 << k) - 1) continue;
			res = min(res, max(dist[n][i], dist[n][j]));
		}
	}
	printf("%lld\n", res);
}