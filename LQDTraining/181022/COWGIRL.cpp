#include <bits/stdc++.h>
using namespace std;

const int N = 32;
const int MASK = 35;

int tc, m, n, dp[N][MASK];

bool match(int x, int y) {
	for (int i = 0; i < n - 1; ++ i) {
		if (((x & y) & (3 << i)) == (3 << i)) return false;
		if (((x | y) & (3 << i)) == 0) return false;
	}
	return true;
}

int main() {
	freopen("COWGIRL.inp", "r", stdin);
	freopen("COWGIRL.out", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &m, &n);
		if (m < n) swap(m, n);
		for (int mask = 0; mask < (1 << n); ++ mask)
			dp[1][mask] = 1;
		for (int i = 2; i <= m; ++ i) {
			for (int mask2 = 0; mask2 < (1 << n); ++ mask2) {
				dp[i][mask2] = 0;
				for (int mask1 = 0; mask1 < (1 << n); ++ mask1) {
					if (match(mask1, mask2)) {
						dp[i][mask2] += dp[i - 1][mask1];
					}
				}
			}
		}
		int res = 0;
		for (int mask = 0; mask < (1 << n); ++ mask) {
			res += dp[m][mask];
		}
		printf("%d\n", res);
	}
}