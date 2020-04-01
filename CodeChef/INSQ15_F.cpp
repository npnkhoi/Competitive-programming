#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long oo = 1e18 + 7;

struct Pack{
	long long dist;
	int vtx, dir;
	Pack(long long a, int b, int c): dist(a), vtx(b), dir(c) {}
};

bool operator > (const Pack a, const Pack b) {
	return a.dist > b.dist;
}

int n, m, h[N], c[N];
long long dist[N][2];
priority_queue<Pack, vector<Pack>, greater<Pack> > heap;
vector<int> adj[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) scanf("%d", &h[i]);
	for (int i = 1; i <= n; ++ i) scanf("%d", &c[i]);
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	heap.push(Pack(c[1], 1, 1));
	heap.push(Pack(c[1], 1, 0));
	dist[1][0] = dist[1][1] = c[1];

	for (int i = 2; i <= n; ++ i) dist[i][0] = dist[i][1] = oo;

	while (!heap.empty()) {
		Pack tmp = heap.top();
		heap.pop();

		if (tmp.dist != dist[tmp.vtx][tmp.dir]) continue;

		for (int v : adj[tmp.vtx]) {
			long long newDist = tmp.dist;
			int change = h[v] - h[tmp.vtx];

			if (change == 0) {
				if (newDist < dist[v][tmp.dir]) {
					dist[v][tmp.dir] = newDist;
					heap.push(Pack(newDist, v, tmp.dir));
				}
				if (newDist + c[tmp.vtx] < dist[v][tmp.dir ^ 1]) {
					dist[v][tmp.dir ^ 1] = newDist + c[tmp.vtx];
					heap.push(Pack(newDist + c[tmp.vtx], v, tmp.dir ^ 1));
				}
				continue;
			}
			int newDir = change > 0;
			if (newDir != tmp.dir) newDist += c[tmp.vtx];

			if (newDist < dist[v][newDir]) {
				dist[v][newDir] = newDist;
				heap.push(Pack(newDist, v, newDir));
				// cerr << tmp.vtx << " -> " << newDist << " " << v << " " << newDir << "\n";
			}
		}	
	}
	long long res = min(dist[n][0], dist[n][1]);
	printf("%lld\n", (res == oo ? -1 : res));
}