#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 55;
const int K = 105;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, k, a[6][N], mark[6][N];
ii trace[6][N];
int flag, cnt;
queue<ii> q;
vector<iii> ans;
ii des[K], dep[K];

bool inBoard(int x, int y) {
	return 1 <= x && x <= 4 && 1 <= y && y <= n;
}

bool park(int x) {
	memset(mark, 0, sizeof mark);
	while (!q.empty()) q.pop();

	q.push(dep[x]);
	// cerr << "park " << x << " " << dep[x].fi << " " << dep[x].se << "\n";

	while (!q.empty()) {
		ii t = q.front();
		q.pop();
		for (int dir = 0; dir < 4; ++ dir) {
			int u = t.fi + dx[dir];
			int v = t.se + dy[dir];
			if (!inBoard(u, v)) continue;
			if (make_pair(u, v) == des[x]) {
				// cerr << "---- to" << u << " " << v << "\n";
				trace[u][v] = t;
				return true;
			} else if (!mark[u][v] && (u == 2 || u == 3) && a[u][v] == 0) {
				// cerr << "---- to" << u << " " << v << "\n";
				trace[u][v] = t;
				mark[u][v] = 1;
				q.push(make_pair(u, v));
			}
		}
	}
	return false;
}

void move(int car, int x, int y) {
	// cerr << "move " << car << " " << x << " " << y << "\n";
	if (x == 1 || x == 4 || a[x][y] != car) {
		move(car, trace[x][y].fi, trace[x][y].se);
		ans.push_back(make_pair(car, make_pair(x, y)));
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= 4; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &a[i][j]);
			if (a[i][j]) {
				if (i == 1 || i == 4) {
					des[a[i][j]] = make_pair(i, j);
				} else {
					dep[a[i][j]] = make_pair(i, j);
				}
			}
		}
	}
	cnt = 0;
	while (1) {
		flag = 0;
		for (int i = 2; i <= 3; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				if (a[i][j] != 0 && park(a[i][j])) {
					move(a[i][j], des[a[i][j]].fi, des[a[i][j]].se);
					a[i][j] = 0;
					flag = 1;
					cnt ++;
				}
			}
		}
		if (!flag) break;
	}
	if (cnt < k) {
		printf("-1");
	} else {
		printf("%d\n", (int) ans.size());
		for (iii u : ans) {
			printf("%d %d %d\n", u.fi, u.se.fi, u.se.se);
		}
	}
}