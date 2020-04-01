#include <bits/stdc++.h>
using namespace std;

#define task "KMAX"

const int N = 305;

int n, a[N], f[N][N];

int LCS(int a[], int m, int b[], int n) {
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			f[i][j] = max(f[i-1][j], f[i][j-1]);
			if (a[i] < b[j]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
 		}
	}
	return f[m][n];
}
int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	int res = 0;
	for (int split = 1; split < n; split ++) {
		res = max(res, LCS(a, split, a + split, n - split));
	}
	printf("%d", res);
}