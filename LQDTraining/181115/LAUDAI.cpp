#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int m, n, a[N][N];
int id[N][N], sz[N * N], res, counter;
set<int> data;
set<int>::iterator it;

bool inBoard(int x, int y) {
	return 1 <= x && x <= m && 1 <= y && y <= n;
}

void dfs(int i, int j) {
	sz[id[i][j]] ++;
	for (int dir = 0; dir < 4; ++ dir) {
		int u = i + dx[dir];
		int v = j + dy[dir];
		if (!inBoard(u, v)) continue;
		if (a[u][v] == 0 && id[u][v] == 0) {
			id[u][v] = counter;
			dfs(u, v);
		}
	}
}

int main() {
	scanf("%d%d", &m, &n);
	char ch;
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf(" %c", &ch);
			a[i][j] = (ch == '1');
		}
	}
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if (a[i][j] == 0 && id[i][j] == 0) {
				id[i][j] = ++ counter;
				dfs(i, j);
				// cerr << i << " " << j << " " << sz[id[i][j]] << "\n";
				res = max(res, sz[id[i][j]]);
			}
		}
	}
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if (a[i][j] == 1) {
				data.clear();
				for (int dir = 0; dir < 4; ++ dir) {
					int u = i + dx[dir], v = j + dy[dir];
					if (!inBoard(u, v) || a[u][v] == 1) continue;
					data.insert(id[u][v]);
				}	
				int tmp = 0;
				for (it = data.begin(); it != data.end(); ++ it) {
					tmp += sz[* it];
				}
				res = max(res, tmp + 1);
			}
		}
	}
	printf("%d\n", res);
}