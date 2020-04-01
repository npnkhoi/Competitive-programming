#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1e4 + 5;

int tc, n, m, k, a[N], f[N][M];

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
		}
		f[0][0] = 1;
		for (int i = 1; i <= n; ++ i) {
			for (int j = 0; j <= m; ++ j) {
				f[i][j] = 0;
				if (f[i-1][j] == -1) {
					f[i][j] = -1;
					continue;
				} else f[i][j] = f[i-1][j];

				if (a[i] <= j) {
					if (f[i-1][j-a[i]] == -1 || f[i][j] + f[i-1][j-a[i]] >= k) {
						f[i][j] = -1;
					} else f[i][j] += f[i-1][j-a[i]];
				}
				// cerr << f[i][j] << "\n";
			}
		}
		if (f[n][m] == -1) printf("ENOUGH\n");
		else printf("%d\n", f[n][m]);
	}
}