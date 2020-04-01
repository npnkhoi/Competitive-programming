#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int tc, m, n, f[N][N];
char a[N], b[N];

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%s %s", a + 1, b + 1);
		m = strlen(a + 1);
		n = strlen(b + 1);
		for (int i = 1; i <= m; ++ i) f[i][0] = i;
		for (int j = 1; j <= n; ++ j) f[0][j] = j;
		for (int i = 1; i <= m; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				f[i][j] = 1 + min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1]);
				if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i-1][j-1]);
			}
		}
		printf("%d\n", f[m][n]);
	}
}