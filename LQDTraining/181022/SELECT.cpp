#include <bits/stdc++.h>
using namespace std;

const int N = 22;
const int MASK = (1 << 20) + 2;

int n, a[N][N], dp[MASK];

int main() {
	freopen("SELECT.inp", "r", stdin);
	freopen("SELECT.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int mask = 1; mask < (1 << n); ++ mask) {
		int row = __builtin_popcount(mask);
		for (int j = 0; j < n; ++ j) {
			if (mask & (1 << j)) {
				dp[mask] = max(dp[mask], dp[mask ^ (1 << j)] + a[row][j + 1]);
			}
		}
	}
	printf("%d\n", dp[(1 << n) - 1]);
}