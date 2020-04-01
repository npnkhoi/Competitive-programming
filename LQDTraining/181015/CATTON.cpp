#include <bits/stdc++.h>
using namespace std;

const int N = 32;
const int K = 52;
const long long oo = 1e18;

int m, n, k;
long long f[N][N][K];

long long dp(int m, int n, int k) {
	if (m * n == k || k == 0) return 0;
	if (f[m][n][k] != -1) return f[m][n][k];
	// cerr << m << " " << n << " " << k << "\n";
	long long tmp = oo;
	for (int p = 1; p < m; ++ p) {
		for (int x = 0; x <= k/2; ++ x) {
			tmp = min(tmp, n * n + dp(p, n, x) + dp(m - p, n, k - x));
		}
	}
	for (int p = 1; p < n; ++ p) {
		for (int x = 0; x <= k / 2; ++ x) {
			tmp = min(tmp, m * m + dp(m, p, x) + dp(m, n - p, k - x));
		}
	}
	// cerr << m << " " << n << " " << k << " " << tmp << "\n";
	return f[m][n][k] = tmp;
}

int main() {
	freopen("CATTON.inp", "r", stdin);
	freopen("CATTON.out", "w", stdout);
	memset(f, -1, sizeof f);
	scanf("%d%d%d", &m, &n, &k);
	printf("%lld\n", dp(m, n, k));
}