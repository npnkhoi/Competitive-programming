#include <bits/stdc++.h>
using namespace std;

const int N = 22;
const int MASK = (1 << 20) + 2;
const int oo = 1e9 + 7;

int n, c[N][N], dp[MASK][N], res;

int main() {
	freopen("DULICH.inp", "r", stdin);
	freopen("DULICH.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &c[i][j]);
		}
	}
	for (int mask = 1; mask < (1 << n); ++ mask) {
		if (__builtin_popcount(mask) == 1) continue;

		for (int i = 0; i < n; ++ i) if (mask & (1 << i)) {
			dp[mask][i] = oo;
			for (int j = 0; j < n; ++ j) if ((mask & (1 << j)) && (j != i)) {
				dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + c[j + 1][i + 1]);
			}
			// cerr << dp[mask][i] << "\n";
		}

	}
	res = oo;
	for (int i = 0; i < n; ++ i) {
		res = min(res, dp[(1 << n) - 1][i]);
	}
	printf("%d", res);
}