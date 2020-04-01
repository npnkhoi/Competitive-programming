#include <bits/stdc++.h>
using namespace std;

#define task "CHENBI"

const int N = 105;
const int M = 7;
const int oo = 1e9 + 7;

int n, m, a[N], f[N][N], g[N][N][M];

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	for (int r = 1; r <= n; ++ r) {
		for (int l = r; l >= 1; -- l) {
			// calc G
			for (int x = 0; x <= m; ++ x) {
				if (a[l] != a[r]) g[l][r][x] = oo;
				else if (l == r) g[l][r][x] = x - (x > 0);
				else {
					g[l][r][x] = oo;
					for (int k = l; k < r; ++ k) {
						g[l][r][x] = min(g[l][r][x] , g[l][k][x - (x > 0)] + f[k + 1][r - 1]);
					}
				}
				// printf("g(%d, %d, %d) = %d\n", l, r, x, g[l][r][x]);
			}
			// calc F
			f[l][r] = g[l][r][m];
			for (int k = l; k < r; ++ k) {
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
			} 
			// printf("f(%d, %d) = %d\n", l, r, f[l][r]);
		}
	}
	printf("%d", f[1][n]);
}