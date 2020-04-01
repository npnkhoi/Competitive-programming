#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N = 1005;

int n, d, f[N][N], res;
pair<int, int> a[N];

int main() {
	freopen("MUSIC.inp", "r", stdin);
	freopen("MUSIC.out", "w", stdout);
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i].fi);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i].se);
	sort(a + 1, a + n + 1);
	// f(i, j) = largest gift by watching j shows from i first shows
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			f[i][j] = f[i-1][j];
			if (j * d <= a[i].fi) f[i][j] = max(f[i][j], f[i-1][j-1] + a[i].se);
		}
	}
	for (int i = 1; i <= n; ++i) res = max(res, f[n][i]);
	printf("%d", res);
}