#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int tc, m, n, ans[2*N];
char str[N][N];

int main() {
	char ch;
	scanf("%d", &tc);
	while (tc--) {
		memset(ans, 0, sizeof ans);
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf(" %c", &str[i][j]);
			}
		}
		for (int i = 1; i <= m; ++ i) {
			for (int j = 1; j <= n; ++ j) if (str[i][j] == '1') {
				for (int k = 1; k <= m; ++ k) {
					for (int l = 1; l <= n; ++ l) if ((i != k || j != l) && str[k][l] == '1') {
						ans[abs(i - k) + abs(j - l)] ++;
					}
				}
			}
		}
		for (int i = 1; i <= m + n - 2; ++i) 
			printf("%d ", ans[i] / 2);
		printf("\n");
	}
}