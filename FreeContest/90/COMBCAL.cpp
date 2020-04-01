#include <bits/stdc++.h>
using namespace std;

const int md = 1e7 + 19;

long long f[2 * md + 5];
int tc;
long long m, n, r;

long long Exp(long long a, long long x) {
	if (x == 0) return 1;
	long long res = Exp(a, x / 2);
	res = res * res % md;
	if (x % 2) res = res * a % md;
	return res;
}

int main() {
	// for (int i = 1; i <= 2 * md; ++ i) {
	// 	f[i] = Exp(i, md - 2) % md;
	// }
	scanf("%d", &tc);
	while (tc --) {
		scanf("%lld%lld%lld", &n, &m, &r);
		long long res = (m % md) * (n % md) % md;
		if (m + n - r >= md) res = 0;
		else {
			for (long long i = r - 1; i <= m + n - 2; ++ i) {
				res = res * (i % md) % md;
			}
			for (long long i = 2; i <= m + n - r; ++ i) {
				res = res * Exp(i, md - 2) % md;
			}
		}
		printf("%lld\n", res);
	}
}