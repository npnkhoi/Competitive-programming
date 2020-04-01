#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const long long oo = 1e18 + 7;

int n, k, a[N];
long long f[N][N];

int main() {
	freopen("DANCE.inp", "r", stdin);
	freopen("DANCE.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i) 
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	// f[0][j] = 0;
	for (int i = 1; i <= k; ++ i) {
		f[i][0] =  f[i][1] = oo;
		for (int j = 2; j <= n; ++ j) {
			f[i][j] = min(f[i][j - 1], f[i - 1][j - 2] + (a[j] - a[j - 1]));
		}
	}
	printf("%lld\n", f[k][n]);
}