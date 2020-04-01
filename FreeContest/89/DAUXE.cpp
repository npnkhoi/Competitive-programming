#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 55;
const int K = 105;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, k, a[6][N];
int x, y;
vector<iii> ans;


int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= 4; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &a[i][j]);
			if ((i == 2 || i == 3) && (a[i][j] == 0)) {
				x = i; y = j;
			}
		}
	}

	if (k == 2 * n) {
		for (int i = 1; i <= n; ++ i) {
			if (a[1][i] == a[2][i] && a[1][i] != 0) {
				ans.push_back(make_pair(a[2][i], mp(1, i)));
				a[2][i] = 0;
				x = 2; y = i;
				k --;
				break;
			}
			if (a[3][i] == a[4][i] && a[3][i] != 0) {
				ans.push_back(make_pair(a[3][i], mp(4, i)));
				a[3][i] = 0;
				x = 3; y = i;
				k --;
				break;
			}
		}
		if (k == 2 * n) {
			printf("-1");
			exit(0);
		}
	}
	while (k > 0) {
		// cerr << x << " " << y << "\n";
		if (x == 2 && y < n) {
			if (a[x][y + 1]) {
				ans.push_back(mp(a[x][y + 1], mp(x, y)));
				swap(a[x][y], a[x][y + 1]);
				if (a[2][y] == a[1][y]) {
					ans.push_back(make_pair(a[2][y], mp(1, y)));
					a[2][y] = 0;
					k --;
				}
			}
			y ++;
		} else if (x == 2 && y == n) {
			if (a[x + 1][y]) {
				ans.push_back(mp(a[x + 1][y], mp(x, y)));
				swap(a[x][y], a[x + 1][y]);
				if (a[2][y] == a[1][y]) {
					ans.push_back(make_pair(a[2][y], mp(1, y)));
					a[2][y] = 0;
					k --;
				}
			}
			x ++;
		} else if (x == 3 && y > 1) {
			if (a[x][y - 1]) {
				ans.push_back(mp(a[x][y - 1], mp(x, y)));
				swap(a[x][y], a[x][y - 1]);
				if (a[3][y] == a[4][y]) {
					ans.push_back(make_pair(a[3][y], mp(4, y)));
					a[3][y] = 0;
					k --;
				}
			}
			y --;
		} else {
			if (a[x - 1][y]) {
				ans.push_back(mp(a[x - 1][y], mp(x, y)));
				swap(a[x][y], a[x - 1][y]);
				if (a[3][y] == a[4][y]) {
					ans.push_back(make_pair(a[3][y], mp(4, y)));
					a[3][y] = 0;
					k --;
				}
			}
			x --;
		}
		// cerr << "-------------\n";
		// for (int i = 1; i <= 4; ++ i) {
		// 	for (int j = 1; j <= n; ++ j) {
		// 		cerr << a[i][j] << " ";
		// 	}
		// 	cerr << '\n';
		// }
	}
	printf("%d\n", (int) ans.size());
	for (iii u : ans) {
		printf("%d %d %d\n", u.fi, u.se.fi, u.se.se);
	}
}