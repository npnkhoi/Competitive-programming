#include <bits/stdc++.h>
using namespace std;

const int N = 250 + 3, md = 1e9 + 7;

int n, k, comb[N][N];
long long f[N][N], Exp0[N], Exp1[N];

void build_comb_table(int n) {
	for (int i = 1; i <= n; ++ i) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; ++ j) {
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % md;
		}
	}
	Exp0[0] = Exp1[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		Exp0[i] = Exp0[i - 1] * k % md;
		Exp1[i] = Exp1[i - 1] * (k - 1) % md;
	}
	// for (int i = 1; i <= n; ++ i) {
	// 	for (int j = 0; j <= i; ++ j) {
	// 		cerr << comb[i][j] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
}

long long Pow(int a, long long n) {
	if (n == 0) return 1;
	long long res = Pow(a, n / 2);
	res = res * res % md;
	if (n % 2) res = res * a % md;
	return res;
}

void solve() {
	// basic value
	for (int r = 1; r <= n; ++ r) {
		f[r][0] = Pow((Exp0[n] - Exp1[n] + md) % md, r);
	}
	for (int c = 1; c <= n; ++ c) {
		f[1][c] = Exp0[n - c];
	}

	for (int r = 2; r <= n; ++ r) {
		for (int c = 1; c <= n; ++ c) {
			for (int t = 1; t <= c; ++ t) {
				f[r][c] = (f[r][c] + comb[c][t] * Exp1[c - t] % md * Exp0[n - c] % md * f[r - 1][c - t] % md) % md;
			}
			f[r][c] = (f[r][c] + Exp1[c] * (Exp0[n - c] - Exp1[n - c] + md) % md * f[r - 1][c] % md) % md; 
		}
	}
	// for (int r = 0; r <= n; ++ r) {
	// 	for (int c = 0; c <= n; ++ c) {
	// 		cerr << f[r][c] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
	printf("%lld\n", f[n][n]);
}

int main() {
	scanf("%d%d", &n, &k);

	build_comb_table(n);

	solve();
}