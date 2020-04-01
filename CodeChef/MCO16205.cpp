#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = 12;
const int oo = 1e9 + 7;

struct Edge{
	int vtx, wei, type;
	Edge() {}
	Edge(int a, int b, int c): vtx(a), wei(b), type(c) {}
};
struct Pack{
	int dist, vtx, type;
	Pack() {}
	Pack(int a, int b, int c): dist(a), vtx(b), type(c) {}
};
bool operator > (const Pack a, const Pack b) {
		return a.dist > b.dist;
}

int n, m, k, s, dist[N][K], tran[K][K];
vector<Edge> adj[N];
priority_queue<Pack, vector<Pack>, greater<Pack> > heap;

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 1; i <= k; ++ i) {
		for (int j = 1; j <= k; ++ j) {
			scanf("%d", &tran[i][j]);
		}
	}
	for (int i = 1; i <= m; ++ i) {
		int u, v, c, t;
		scanf("%d%d%d%d", &u, &v, &c, &t);
		adj[u].push_back(Edge(v, c, t));
		adj[v].push_back(Edge(u, c, t));
	}
	heap.push(Pack(0, s, 0));
	for (int i = 1; i <= n; ++ i) if (i != s) {
		for (int j = 1; j <= k; ++ j) {
			dist[i][j] = oo;
		}
	}
	while (!heap.empty()) {
		Pack tmp = heap.top();
		heap.pop();

		if (dist[tmp.vtx][tmp.type] != tmp.dist) continue;

		for (Edge nxt : adj[tmp.vtx]) {
			if (tmp.dist + nxt.wei + tran[tmp.type][nxt.type] < dist[nxt.vtx][nxt.type]) {
				dist[nxt.vtx][nxt.type] = tmp.dist + nxt.wei + tran[tmp.type][nxt.type];
				heap.push(Pack(dist[nxt.vtx][nxt.type], nxt.vtx, nxt.type));
			}
		}
	}
	for (int u = 1; u <= n; ++ u) {
		int res = oo;
		for (int type = 1; type <= k; ++ type) {
			res = min(res, dist[u][type]);
		}
		printf("%d ", (res == oo ? -1 : res));
	}
}