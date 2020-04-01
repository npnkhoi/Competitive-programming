#include <bits/stdc++.h>
using namespace std;

#define task "Q11"

const int N = 505;

int tc, n;
long long a[N][N];
int f[N][N];

int sum(int x, int y, int u, int v) {
	return a[u][v] - a[x-1][v] - a[u][y-1] + a[x-1][y-1];
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				scanf("%lld", &a[i][j]);
				a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
				f[i][j] = 0;
				if (sum(1, j, i, j) % 2 == 0) f[i][j] |= !f[i][j-1];
				if (sum(i, 1, i, j) % 2 == 0) f[i][j] |= !f[i-1][j];
				//cerr << f[i][j] << " ";
			}
			//cerr << "\n";
		}
		if (f[n][n]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}