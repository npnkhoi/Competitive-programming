#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int oo = 1e9 + 7;
// const int dx[] = {-1, 1, 0, 0};
// const int dy[] = {0, 0, -1, 1};

typedef pair<int, int> ii;

int n, m, k1, k2;
int a[N][N], dist1[N][N], dist2[N][N];
queue<ii> q;

bool inBoard(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

void BFS(int x, int y, int k, int dist[][N]) {
	// cerr << x << " " << y << " " << k << "\n";
	q.push(make_pair(x, y));
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			dist[i][j] = oo;
		}
	}
	dist[x][y] = 0;
	int counter = 0;
	while (!q.empty()) {
		int u = q.front().first;
		int v = q.front().second;
		q.pop();
		for (int dx = - k; dx <= k; ++ dx) {
			// |dx - u| + |dy - v| <= k
			for (int dy = - k + abs(dx); dy <= + k - abs(dx); ++ dy) {
				// cerr << "dx dy " << dx << " " << dy << "\n";
				int x = u + dx;
				int y = v + dy;
				if (inBoard(x, y) && dist[x][y] == oo && a[x][y] == 0) {
					q.push(make_pair(x, y));
					dist[x][y] = dist[u][v] + 1;
					// cerr << x << " " << y << "\n";
				}
			}
		}
	}
}

int main() {
	// freopen("CHEFARC.inp", "r", stdin);
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d%d", &n, &m, &k1, &k2);
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= m; ++ j) {
				scanf("%d", &a[i][j]);
			}
		}
		BFS(1, 1, k1, dist1);
		// cerr << "done\n";
		BFS(1, m, k2, dist2);

		int res = oo;
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= m; ++ j) {
				res = min(res, max(dist1[i][j], dist2[i][j]));
			}
		}
		printf("%d\n", (res == oo ? -1 : res));
	}
}