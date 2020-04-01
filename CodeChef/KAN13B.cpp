#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair

const int N = 105;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double oo = 1e9;

typedef pair<double, pair<int, int> > Pack;

int tc, m, n, q;
double h[N][N];
priority_queue<Pack, vector<Pack>, greater<Pack> > heap;
double dist[N][N];

bool operator < (const Pack a, const Pack b) {
	return a.first < b.first;
} 

bool inBoard(int x, int y) {
	return 1 <= x && x <= m && 1 <= y && y <= n;
}

double minPath(int sx, int sy, int ex, int ey) {
	while (!heap.empty()) heap.pop();
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			dist[i][j] = oo;
		}
	}

	heap.push(mp(0, mp(sx, sy)));
	dist[sx][sy] = 0;

	while (!heap.empty()) {
		Pack t = heap.top();
		double d = t.fi;
		int x = t.se.fi, y = t.se.se;
		heap.pop();

		if (d != dist[x][y]) continue;
		if (x == ex && y == ey) return d;

		for (int dir = 0; dir < 4; ++ dir) {
			int u = x + dx[dir];
			int v = y + dy[dir];
			if (!inBoard(u, v)) continue;
			double c;
			if (h[x][y] > h[u][v]) c = 0.5 + 0.5 * sqrt(1 + (h[x][y] - h[u][v]) * (h[x][y] - h[u][v]));
			else c = -0.5 + 1.5 * sqrt(1 + (h[x][y] - h[u][v]) * (h[x][y] - h[u][v]));
			if (d + c < dist[u][v]) {
				dist[u][v] = d + c;
				heap.push(mp(dist[u][v], mp(u, v)));
			}
		}
	}
}

int main() {
	scanf("%d", &tc);
	for (int iTest = 1; iTest <= tc; ++ iTest) {
		scanf("%d %d", &m, &n);
		for (int i = 1; i <= m; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				scanf("%lf", &h[i][j]);
			}
		}
		printf("Case %d:\n", iTest);
		scanf("%d", &q);
		while (q --) {
			int x, y, u, v;
			scanf("%d%d%d%d", &x, &y, &u, &v);
			printf("%.6lf\n", minPath(x, y, u, v));
		}
	}
}