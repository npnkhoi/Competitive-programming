#include <bits/stdc++.h>
using namespace std;

#define task "RACE"

const int N = 305;
const int oo = 1e9 + 7;

int n, a[N][N], f[2 * N][N][N];
int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &n);

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int x = 1; x <= n; ++x) {
		for (int u = 1; u <= n; ++ u) {
			f[1][x][u] = -oo;
		}
	}
	f[1][1][1] = a[1][1];

	for (int s = 2; s <= 2 * n - 1; ++ s) {
		for (int x = 1; x <= n; ++ x) {
			for (int u = 1; u <= n; ++ u) {
				// y + x - 1 = s => y = s + 1 - x
				int y = s + 1 - x;
				int v = s + 1 - u;
				if (1 <= y && y <= n && 1 <= v && v <= n) {
					int delta = a[x][y] + (x != u ? a[u][v] : 0);
					f[s][x][u] = f[s-1][x][u] + delta;
					if (x > 1) f[s][x][u] = max(f[s][x][u], delta + f[s-1][x - 1][u]);
					if (u > 1) f[s][x][u] = max(f[s][x][u], delta + f[s-1][x][u - 1]);
					if (x > 1 && u > 1) f[s][x][u] = max(f[s][x][u], delta + f[s-1][x - 1][u - 1]);
				} else {
					f[s][x][u] = - oo;
				}
				// printf("f(%d %d %d) = %d: (%d, %d) and (%d, %d)\n", s, x, u, f[s][x][u], x, y, u, v);
			}
		}

	}
	printf("%d\n", f[2 * n - 1][n][n]);
}