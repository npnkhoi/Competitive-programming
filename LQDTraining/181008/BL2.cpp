#include <bits/stdc++.h>
using namespace std;

#define task "BL2"

const int N = 1e3 + 5;
const int oo = 1e9 + 7;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, 1, -1, 0};

struct Pack{
	int x, y, dir;
	Pack(): x(0), y(0), dir(0) {}
	Pack(int x, int y, int dir): x(x), y(y), dir(dir) {}
};

int n, a[N][N], dist1[N][N][4], dist2[N][N][4];
queue<Pack> q;

bool inBoard(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void Push(int x, int y, int dir, int distance, int dist[][N][4]) {
	dist[x][y][dir] = distance;
	
	if (a[x][y] == 1) return;

	q.push(Pack(x, y, dir));
	int u = x, v = y;
	while (1) {
		u += dx[dir];
		v += dy[dir];
		if (inBoard(u, v) && dist[u][v][dir] == oo) {
			if (a[u][v] == 0) {
				q.push(Pack(u, v, dir));
				dist[u][v][dir] = distance;	
			} else {
				dist[u][v][dir] = distance;	
				break;
			}
		} else {
			break;
		}
	}
}

void BFS(int x, int y, int dist[][N][4]) {
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			for (int dir = 0; dir < 4; ++ dir) {
				dist[i][j][dir] = oo;
			}
		}
	}
	for (int dir = 0; dir < 4; ++ dir) {
		Push(x, y, dir, 0, dist);
	}
	while (!q.empty()) {
		Pack tmp = q.front();
		q.pop();

		int x = tmp.x;
		int y = tmp.y;
		int dir_ = tmp.dir;
		int distance = dist[x][y][dir_];

		for (int dir = 0; dir < 4; ++ dir) if (dir != dir_) {
			int u = x + dx[dir];
			int v = y + dy[dir];
			if (inBoard(u, v) && dist[u][v][dir] == oo) {
				Push(u, v, dir, distance + 1, dist);
			}
		}
	}
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &a[i][j]);
		}
	}
	int x, y, p, q;
	scanf("%d%d", &x, &y);
	scanf("%d%d", &p, &q);

	BFS(x, y, dist1);
	BFS(p, q, dist2);
	int res = oo;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			for (int dir1 = 0; dir1 < 4; ++ dir1) {
				for (int dir2 = 0; dir2 < 4; ++ dir2) {
					res = min(res, dist1[i][j][dir1] + dist2[i][j][dir2] + (dir1 != 3 - dir2));
				}
			}
		}
	}

	if (res < oo) printf("%d", res);
	else printf("-1\n");
}