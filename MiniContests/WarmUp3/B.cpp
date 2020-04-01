#include <bits/stdc++.h>
using namespace std;

const int md = 1e6;

int tc;
long long n, res;

int ans(int n) {
	int res = 0;
	for (int i = 1; i <= n; ++ i) {
		res += n / i;
		// printf("%d div %d = %d\n", n, i, n/i);
	}
	return res;
}

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%lld", &n);
		// cout << ans(n) << "\n";
		int m = sqrt(n);
		res = 0;
		for (int i = 1; i <= m; ++ i) {
			res = (res + i * (n / i - n / (i + 1))) % md;
		}
		for (int i = 1; i <= n / (m + 1); ++ i) {
			res = (res + n / i) % md;
		}
		printf("%lld\n", res);
	}
}