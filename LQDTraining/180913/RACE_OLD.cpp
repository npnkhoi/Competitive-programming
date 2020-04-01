#include <bits/stdc++.h>
using namespace std;

#define task "RACE"

const int N = 305;
const int oo = 1e9 + 7;

int n, a[N][N], f[N][N][N][2];

// void trace(int i, int j, int x) {
	
// } 
int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int l = 1; l <= n; ++ l) {
		for (int r = 1; r <= n; ++ r) {
			f[0][l][r][1] = - oo;
		}
	}
	f[0][1][1][1] = 0;

	for (int i = 1; i <= n; ++ i) {
		for (int l = 1; l <= n; ++ l) {
			for (int r = 1; r <= n; ++ r) {
				f[i][l][r][0] = f[i-1][l][r][1] + a[i][l] + (l == r ? 0 : a[i][r]);
				// printf("pre 0: %d\n", f[i][l][r][0]);
				if (l > 1) {
					f[i][l][r][0] = max(f[i][l][r][0], f[i][l-1][r][0] + (l == r ? 0 : a[i][l]));
				}

				f[i][l][r][1] = max(f[i-1][l][r][1] + a[i][l] + (l == r ? 0 : a[i][r]), f[i][l][r][0]);
				if (r > 1) {
					if (l < r) {
						f[i][l][r][1] = max(f[i][l][r][1], f[i][l][r-1][1] + a[i][r]);
					} else {
						f[i][l][r][1] = max(f[i][l][r][1], f[i][l][r-1][1]);
					}
				}
				printf("f(%d, %d, %d) = %d, %d\n", i, l, r, f[i][l][r][0], f[i][l][r][1]);
			}
		}
	}
	printf("%d", f[n][n][n][1]);
}