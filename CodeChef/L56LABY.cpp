#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

typedef pair<int, int> ii;

int n, m, a[N][N], mark[N][N];
vector<ii> cell[N*N];
queue<ii> q;

bool inBoard(int x, int y) {
	return 1 <= x && x <= m && 1 <= y && y <= n;
}

int main() {
	// freopen("L56LABY.inp", "r", stdin);
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m * n; ++ i) {
			cell[i].clear();
		}
		for (int i = 1; i <= m; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				scanf("%d", &a[i][j]);
				a[i][j] = min(a[i][j], m * n);
				if (a[i][j] >= 1) {
					cell[a[i][j]].push_back(make_pair(i, j));
				}
			}
		}
		memset(mark, 0, sizeof mark);
		while (!q.empty()) q.pop();
		for (int i = m * n; i >= 0; -- i) {
			int siz = q.size();
			while (siz --) {
				ii u = q.front();
				q.pop();
				for (int dir = 0; dir < 4; ++ dir) {
					int x = u.first + dx[dir];
					int y = u.second + dy[dir];
					if (inBoard(x, y) && !mark[x][y] && a[x][y] >= 0) {
						mark[x][y] = 1;
						q.push(make_pair(x, y));
						// cerr << i << " " << x << " " << y << "\n";
					}
				}
			}
			for (ii t : cell[i]) {
				int u = t.first;
				int v = t.second;
				if (!mark[u][v])
					mark[u][v] = 1;
					q.push(make_pair(u, v));
					// cerr << i << " " << u << " " << v << "\n";
				}
		}
		for (int i = 1; i <= m; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				if (a[i][j] == -1) {
					printf("B");
				} else printf("%c", (mark[i][j] ? 'Y' : 'N'));
			}
			printf("\n");
		}
	}
}