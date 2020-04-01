#include <bits/stdc++.h>
using namespace std;

void bfs(int x, int y) {
	memset(dist, 0, sizeof dist);
	Push(x, y, 1);
	while (!q.empty()) {
		ii t = q.front();
		q.pop();
		for (int dir = 0; dir < 4; ++ dir) {
			int u = t.first, v = t.second;
			if (inBoard(u, v) && vis[u][v] == 0) {
				Push(u, v, dist[t.first][t.second] + 1);
			}
		}
	}
}

int main() {
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf(" %c", &a[i][j]);
		}
	}
	bfs(i, j);
	printf("%d\n", res);
}