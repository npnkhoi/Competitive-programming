#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m, a[N][N], mark[N][N];
queue<pair<int, int> > q;

bool inBoard(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &n, &m);
		int maxVal = 0;
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= m; ++ j) {
				scanf("%d", &a[i][j]);
				maxVal = max(maxVal, a[i][j]);
			}
		}
		// cerr << "max val " << maxVal << "\n";
		memset(mark, 0, sizeof mark);
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= m; ++ j) {
				if (a[i][j] == maxVal) {
					q.push(make_pair(i, j));
					mark[i][j] = 1;
					// cerr << "pre push " << i << " " << j << "\n";
				}
			}
		}
		int res = -1;
		while (!q.empty()) {
			res ++;
			int sz = q.size();
			while (sz --) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int dir = 0; dir < 8; ++ dir) {
					int u = x + dx[dir];
					int v = y + dy[dir];
					if (inBoard(u, v) && mark[u][v] == 0) {
						q.push(make_pair(u, v));
						// cerr << u << " " << v << "\n";
						mark[u][v] = 1;
					}
				}
			}
		}
		printf("%d\n", res);
	}
}