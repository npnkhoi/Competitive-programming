#include <bits/stdc++.h>
using namespace std;

const int K = 1e6 + 5;
const int D = 1e2 + 5;
const int md = 1e9 + 7;

int n, k, cnt[D];
long long f[K], res;

int main() {
	scanf("%d%d", &n, &k);
	int x;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &x);
		cnt[x] ++;
	}
	if (n == 1) {
		printf("%d\n", k / x + 1);
		return 0;
	}

	f[0] = 1; res = 1;
	for (int i = 1; i <= k; ++ i) {
		f[i] = 0;
		for (int j = max(0, i - 100); j <= i - 1; ++ j) {
			f[i] = (f[i] + f[j] * cnt[i - j] % md) % md;
		}
		res = (res + f[i]) % md;
	}
	printf("%lld\n", res);
}