#include <bits/stdc++.h>
using namespace std;
long long a[55];
int n, tc;
int main() {
	freopen("WC5.inp", "r", stdin);
	freopen("WC5.ans", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
		long long res = 0;
		for (int x = 1; x <= n; x ++) {
			for (int y = x + 1; y <= n; y ++) {
				for (int z = y + 1; z <= n; z ++) {
					for (int t = z + 1; t <= n; t ++) {
						if (a[x] * a[y] * a[z] == a[t]) {
							res ++;
						}
					}
				}
			}
		}
		printf("%lld\n", res);
	}
}