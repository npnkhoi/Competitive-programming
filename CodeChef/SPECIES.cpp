#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const long long md = 1e9 + 7;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

typedef pair<int, int> ii;

int n;
queue<ii> q;
int mark[N][N], siz;
char a[N][N];
bool flag;

bool inBoard(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void floodBP(int x, int y) {
	char species = a[x][y];

	q.push(make_pair(x, y));
	mark[x][y] = 1;

	while (!q.empty()) {
		ii u = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++ dir) {
			int i = u.first + dx[dir];
			int j = u.second + dy[dir];
			if (inBoard(i, j) && !mark[i][j] && a[i][j] != '.') {
				if (a[i][j] == '?' || a[i][j] == species) {
					a[i][j] = species;
					mark[i][j] = 1;
					q.push(make_pair(i, j));
				} else {
					flag = 1;
					break;
				}
			}
		}
	}
}

void checkG(int x, int y) {
	for (int dir = 0; dir < 4; ++ dir) {
		int u = x + dx[dir];
		int v = y + dy[dir];
		if (inBoard(u, v) && a[u][v] != '.') {
			flag = 1;
			return;
		}
	}
}

void flood(int x, int y) {
	// cerr << "flood " << x << " " << y << "\n";
	q.push(make_pair(x, y));
	mark[x][y] = 1;
	siz = 1;

	while (!q.empty()) {
		ii u = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++ dir) {
			int i = u.first + dx[dir];
			int j = u.second + dy[dir];
			if (inBoard(i, j) && !mark[i][j] && a[i][j] == '?') {
				mark[i][j] = 1;
				// cerr << i << " " << j << "\n";
				q.push(make_pair(i, j));
				siz ++;
			}
		}
	}
	// cerr << "\n";
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				scanf(" %c", &a[i][j]);
			}
		}
		flag = 0;
		memset(mark, 0, sizeof mark);

		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				if (a[i][j] == 'B' || a[i][j] == 'P') {
					floodBP(i, j);
				}
				if (a[i][j] == 'G') {
					checkG(i, j);
				}
			}
		}
		if (flag) {
			printf("0\n");
			continue;
		}

		long long res = 1;

		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				if (a[i][j] == '?' && !mark[i][j]) {
					flood(i, j);
					// cerr << siz << "\n";
					if (siz == 1) {
						res = res * 3 % md;
					} else {
						res = res * 2 % md;
					}
				}
			}
		}

		printf("%lld\n", res);
	}
}