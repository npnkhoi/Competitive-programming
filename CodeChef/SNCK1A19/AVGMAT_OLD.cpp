#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int tc, m, n, p, q, sh;
int minRow, maxRow, minCol, maxCol;
int a[2*N][2*N], s[2*N][2*N], ans[2*N];
char str[N][N];

int sum(int x, int y, int u, int v) {
	if (x > maxRow || u < minRow || y > maxCol || v < minCol) return 0;
	x = max(x, minRow);
	y = max(y, minCol);
	u = min(u, maxRow);
	v = min(v, maxCol);
	return s[u + sh][v] - s[x - 1 + sh][v] - s[u + sh][y - 1] + s[x - 1 + sh][y - 1];
}

int main() {
	char ch;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &m, &n);
		sh = n;
		minRow = 1 - n;
		maxRow = m - 1;
		minCol = 2;
		maxCol = m + n;
		memset(a, 0, sizeof a);
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf(" %c", &str[i][j]);
				a[i - j + sh][i + j] = (str[i][j] == '1');
			}
		}
		memset(s, 0, sizeof s);
		for (int i = minRow + sh; i <= maxRow + sh; ++i) {
			for (int j = minCol; j <= maxCol; ++j) {
				s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			}
		}
		memset(ans, 0, sizeof ans);
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++ j) if (str[i][j] == '1') {
				// cerr << "at " << i << " " << j << "\n";
				int maxD = max(i - 1, m - i) + max(j - 1, n - j);
				for (int d = 1; d <= maxD; ++d) {
					int tmp = 0;
					if (i - j - d >= minRow)
						tmp += sum(i - j - d, i + j - d, i - j - d, i + j + d - 1);
					if (i - j + d <= maxRow)
						tmp += sum(i - j + d, i + j - d + 1, i - j + d, i + j + d);
					if (i + j - d >= minCol)
						tmp += sum(i - j - d + 1, i + j - d, i - j + d, i + j - d);
					if (i + j + d <= maxCol)			
						tmp += sum(i - j - d, i + j + d, i - j + d - 1, i + j + d);
					// cerr << tmp << "\n";
					ans[d] += tmp;
				}
			}
		}
		for (int i = 1; i <= m + n - 2; ++i) 
			printf("%d ", ans[i]/2);
		printf("\n");
	}
}