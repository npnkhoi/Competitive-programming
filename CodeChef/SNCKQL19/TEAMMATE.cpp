#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long md = 1e9 + 7;

int tc, n, m, a[N], b[N];
vector<long long> f[N];
long long fac[N];

long long Exp(long long a, long long x) {
	// cerr << "exp " << a << " " << x << "\n"; 
	if (x == 0) return 1;
	long long res = Exp(a, x / 2);
	res = res * res % md;
	if (x % 2) res = res * a % md;
	return res;
} 

int main() {
	f[0].push_back(1);
	
	fac[0] = 1;
	for (int i = 1; i <= 1e5; ++ i) {
		fac[i] = fac[i - 1] * i % md;
	}

	for (int i = 2; i <= 1e5; i += 2) {
		fuck[i] = (i - 1) * fuck[i - 2] % md;
	}

	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		int cnt = 0;
		m = 0;
		for (int i = 1; i <= n; ++ i) {
			if (i > 1 && a[i] != a[i - 1]) {
				b[++m] = cnt;
				cnt = 1;
			} else {
				++ cnt;
			}
		}
		if (cnt > 0) b[++m] = cnt;

		// cerr << "array b" << "\n";
		// for (int i = 1; i <= m; ++ i) {
		// 	cerr << b[i] << " ";
		// }
		// cerr << "\n";

		// for (int i = 1; i <= m; ++ i) {
		// 	f[i].resize(b[i] + 1);
		// 	f[i][0] = f[i - 1][b[i - 1]];
		// 	// cerr << i << " 0 " << f[i][0] << "\n";
		// 	for (int j = 1; j <= b[i]; ++ j) {
		// 		f[i][j] = 0;
		// 		if (j >= 2) f[i][j] = 1LL * j * (j - 1) / 2 % md * f[i][j - 2] % md;
		// 		// cerr << i << " " << j << " " << f[i][j] << "\n";
		// 		// if (j <= b[i - 1]) {1
		// 		// 	f[i][j] = (f[i][j] + 
		// 		// 		fac[b[i - 1]] * Exp(fac[b[i - 1] - j], md - 2) % md * f[i - 1][b[i - 1] - j] % md) % md;
		// 		// 	// cerr << "exp " << fac[b[i - 1] - j] << "\n";
		// 		// }
		// 		if (j == 1) {
		// 			f[i][j] = (f[i][j] + b[i - 1] * f[i - 1][b[i - 1] - 1] % md) % md;
		// 		}
		// 		// cerr << i << " " << j << " " << f[i][j] << "\n";
		// 	}
		// }
		// printf("%lld\n", f[m][b[m]]);
		// for (int i = 1; i <= m; ++ i) {
		// 	f[i].clear();
		// }


		for (int i = 1; i <= m; ++ i) {
			if (g[i] % 2)
		}
 	}
}