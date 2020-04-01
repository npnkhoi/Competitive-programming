#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int m, n, a[N][N], l[N], r[N], h[N];
int res;

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= m; ++ i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++ j) {
			if (j == 1 || a[i][j-1] <= a[i][j]) {
				++ cnt;
				res = max(res, cnt);
			} else {
				cnt = 1;
			}
		}
	}	
	for (int j = 1; j <= n; ++ j) {
		int cnt = 0;
		for (int i = 1; i <= m; ++ i) {
			if (i == 1 || a[i-1][j] <= a[i][j]) {
				++ cnt;
				res = max(res, cnt);
			} else {
				cnt = 1;
			}
		}
	}

	-- m; -- n;
	//cerr << "ok\n";
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			if (a[i][j] <= a[i][j + 1] && a[i + 1][j] <= a[i + 1][j + 1] 
				&& a[i][j] <= a[i + 1][j] && a[i][j + 1] <= a[i + 1][j + 1]) {
				++ h[j]; 
			} else {
				h[j] = 0;
			}
			//cerr << h[j] << " ";
		}
		// cerr << "\n";
		for (int j = 1; j <= n; ++ j) {
			int tmp = j - 1;
			while (tmp > 0 && h[tmp] >= h[j]) {
				//cerr << "tmp = " << tmp << "\n";
				tmp = l[tmp];
			}
			l[j] = tmp;
		}
		for (int j = n; j >= 1; -- j) {
			int tmp = j + 1;
			while (tmp < n + 1 && h[tmp] >= h[j]) {
				tmp = r[tmp];
			}
			r[j] = tmp;
			if (h[j]) res = max(res, (r[j] - l[j]) * (h[j] + 1));
		}
	}

	printf("%d\n", res);
}