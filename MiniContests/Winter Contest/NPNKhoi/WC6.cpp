#include <bits/stdc++.h>
using namespace std;
#define task "WC6"
const int M = 7;
const int K = 22;

int tc, n, m, c, k;
long long dp[55][(1 << M) + 5][K][K];
int cntPairs[(1 << M) + 5];

bool bitOn(int mask, int idx) {
	return (mask & (1 << idx)) > 0;
}
int match(int x, int y) {
	return __builtin_popcount(x & y) + cntPairs[y];
}
void init() {
	for (int mask = 0; mask < (1 << M); mask ++) {
		for (int i = 0; i < M - 1; i ++) {
			cntPairs[mask] += bitOn(mask, i) & bitOn(mask, i + 1);
		}
		//cerr << "cnt pairs " << mask << " = " << cntPairs[mask] << "\n"; 
	}
}
int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	init();
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d%d", &m, &n, &c, &k);
		if (m > n) swap(m, n);
		// cerr << n << " " << m << " " << c << " " << k << '\n';
		dp[0][0][0][0] = 1;
		for (int i = 1; i <= n; ++ i) {
			for (int last = 0; last < (1 << m); ++ last) {
				for (int cows = 0; cows <= c; ++ cows) {
					for (int pairs = 0; pairs <= k; ++ pairs) {
						dp[i][last][cows][pairs] = 0;
						for (int pre = 0; pre < (1 << m); ++ pre) {
							int _pairs = match(pre, last);
							int _cows = __builtin_popcount(last);
							if (_cows <= cows && _pairs <= pairs) {
								dp[i][last][cows][pairs] += dp[i-1][pre][cows - _cows][pairs - _pairs];
								// cerr << "back to " << i-1 << " " << pre << " " << cows - _cows << " " << pairs - _pairs 
								// << " (" << pairs << " " << cows << ")\n";
							}
						}
						// if (dp[i][last][cows][pairs])
						// cerr << "dp(" << i << " " << last << " " << cows << " " << pairs << ") = " << dp[i][last][cows][pairs] << "\n";
					}
				}
			}
		}
		long long res = 0;
		for (int last = 0; last < (1 << m); ++ last) {
			for (int pairs = 0; pairs <= k; pairs ++) {
				res += dp[n][last][c][pairs];
			}
		}
		printf("%lld\n", res);
	}
}