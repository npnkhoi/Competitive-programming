#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k, a[N];
long  long s[N], f[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= k - 1 && i <= n; ++ i) f[i] = s[i];
	for (int i = k; i <= n; ++ i) {
		for (int j = i - k; j < i; ++ j) {
			f[i] = max(f[i], f[j] + s[i] - s[j + 1]);
		}
	}
	printf("%lld\n", f[n]);
}