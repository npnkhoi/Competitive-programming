#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, k, md, a[N], f[N][N];
long long res = 0;

int main() {
	freopen("E.inp", "r", stdin);
	freopen("E.out", "w", stdout);
	scanf("%d%d%d", &n, &k, &md);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= n; ++ i) f[i][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= k && j <= i; ++ j) {
			f[i][j] = (f[i - 1][j] + 1LL * a[i] * f[i - 1][j - 1]) % md;
		}
	}
	printf("%d", f[n][k]);
}