#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = 1e4 + 5;
const int oo = 1e9 + 7;

typedef pair<int, int> ii;

int n, m, k, speNode[K], spe[N], dist[N], source[N];
vector<ii> adj[N];
priority_queue<ii, vector<ii>, greater<ii> > heap;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; ++ i) {
		scanf("%d", &speNode[i]);
		spe[speNode[i]] = 1;
	}
	for (int i = 1; i <= m; ++ i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}
	for (int i = 1; i <= n; ++ i) {
		source[i] = i; 
		if (spe[i]) {
			dist[i] = 0;
			heap.push(make_pair(0, i));
		} else {
			dist[i] = oo;
		}
	}

	int res = oo;
	while (!heap.empty()) {
		ii tmp = heap.top();
		heap.pop();

		if (tmp.first != dist[tmp.second]) continue;

		for (ii v : adj[tmp.second]) {
			if (source[v.first] != source[tmp.second]) {
				res = min(res, dist[v.first] + tmp.first + v.second);
			}
			if (tmp.first + v.second < dist[v.first]) {
				// res = min(res, dist[v.first] + tmp.first + v.second);
				dist[v.first] = tmp.first + v.second;
				source[v.first] = source[tmp.second];
				heap.push(make_pair(dist[v.first], v.first));
				// printf("%d %d\n", dist[v.first], v.first);
			}
		}
	}
	printf("%d\n", res);
}