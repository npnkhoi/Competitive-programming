#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int di[] = {'U', 'D', 'L', 'R'};
const int N = 15;

int tc, x, y, a[N][N], mark[N][N], trace[N][N];
queue<pair<int, int> > q;

bool inBoard(int x, int y) {
	return 1 <= x && x <= 12 && 1 <= y && y <= 12;
}

void tracing(int x, int y) {
	if (mark[x][y] == 0) return;
	tracing(x - dx[trace[x][y]], y - dy[trace[x][y]]);
	printf("%c", di[trace[x][y]]);
}

void solve(int x, int y) {
	if (a[x][y] == 1) {
		printf("0\n\n");
		return;
	}
	while (!q.empty()) q.pop();
	memset(mark, -1, sizeof mark);
	q.push({x, y});
	mark[x][y] = 0;

	while (1) {
		auto t = q.front();
		q.pop();
		for (int dir = 0; dir < 4; ++ dir) {
			int u = t.first + dx[dir], v = t.second + dy[dir];
			if (!inBoard(u, v) || a[u][v] == 2 || mark[u][v] != -1) continue;
			
			mark[u][v] = mark[t.first][t.second] + 1;
			trace[u][v] = dir;

			if (a[u][v] == 1) {
				// return answer;
				printf("%d\n", mark[u][v]);
				tracing(u, v);
				printf("\n");
				return;
			}
			q.push({u, v});
		}
	}
}

int main() {
	// init
	a[3][3] = a[3][10] = a[10][3] = a[10][10] = 1;
	a[6][6] = a[6][7] = a[7][6] = a[7][7] = 2;
	a[10][2] = a[9][2] = a[9][3] = 2;
	a[9][10] = a[9][11] = a[10][11] = 2;
	// ok go!
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &x, &y);
		solve(x, y);
	}
}