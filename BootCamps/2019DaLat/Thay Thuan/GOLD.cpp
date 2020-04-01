#include <bits/stdc++.h>
using namespace std;

const int N = 42;
const int M = 1e6 + 5;

int n, m, a[N];
long long f[N][M], res;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i <= n; ++ i) f[i][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			f[i][j] = f[i-1][j] + (j >= a[i] ? f[i-1][j - a[i]] : 0);
			// cerr << i << " " << j << " " << f[i][j] << "\n";
 		}
	}
	for (int j = 0; j <= m; ++ j) res += f[n][j];
	printf("%lld", res);
}