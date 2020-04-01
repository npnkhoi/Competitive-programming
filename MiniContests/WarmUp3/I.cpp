#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int tc, m, n, a[N][N], ne[N][N][2], nw[N][N][2], se[N][N][2], sw[N][N][2];

int main() {
	scanf("%d", &tc);
	char ch;
	while (tc --) {
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				scanf(" %c", &ch);
				a[i][j] = (ch == '1');
			}
		}
		memset(nw, 0, sizeof nw);
		memset(ne, 0, sizeof ne);
		memset(sw, 0, sizeof sw);
		memset(se, 0, sizeof se);
		for (int i = 1; i <= m; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				if (a[i][j]) {
					nw[i][j][0] = 1 + max(0, nw[i-1][j][1]);
					nw[i][j][1] = 1 + max(0, nw[i][j-1][0]);
 				}
			}
		}
		for (int i = 1; i <= m; ++ i) {
			for (int j = n; j >= 1; -- j) {
				if (a[i][j]) {
					ne[i][j][0] = 1 + max(0, ne[i-1][j][1]);
					ne[i][j][1] = 1 + max(0, ne[i][j+1][0]);
				}
			}
		}
		for (int i = m; i >= 1; -- i) {
			for (int j = 1; j <= n; ++ j) {
				if (a[i][j]) {
					sw[i][j][0] = 1 + max(0, sw[i+1][j][1]);
					sw[i][j][1] = 1 + max(0, sw[i][j-1][0]);
				}
			}
		}
		for (int i = m; i >= 1; -- i) {
			for (int j = n; j >= 1; -- j) {
				if (a[i][j]) {
					se[i][j][0] = 1 + max(0, se[i+1][j][1]);
					se[i][j][1] = 1 + max(0, se[i][j+1][0]);
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= m; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				if (a[i][j]) {
					res = max(res, nw[i][j][1] + ne[i][j][0] + sw[i][j][0] + se[i][j][1] - 3);
					// cerr << i << " " << j << " " << nw[i][j][1] << " " << ne[i][j][0] << " " <<  sw[i][j][1] << " " <<  se[i][j][0] << "\n";
				}
			}
		}
		printf("%d\n", res);
	}
}