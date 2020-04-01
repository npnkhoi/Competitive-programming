#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N], f[N][N], res, last1, last2;

bool match(int x, int y) {
	if (a[x] == a[x - 1]) {
		return a[y] == a[y - 1];
	} else if (a[x] > a[x - 1]) {
		return a[y] > a[y - 1]; 
	} else {
		return a[y] < a[y - 1];
	}
}

int main() {
	freopen("BL5.inp", "r", stdin);
	freopen("BL5.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++ i) {
		for (int j = i + 1; j <= n; ++ j) {
			if (i > 1 && j > 1 && match(i, j)) {
				f[i][j] = min(1 + f[i - 1][j - 1], j - i);
				// cerr << "ok " << i << " " << j << "\n";
 			} else {
				f[i][j] = 1;
			}
			if (f[i][j] > res) {
				res = f[i][j];
				last1 = i;
				last2 = j;
			}
		}
	}
	// cerr << res << "\n";
	printf("%d %d\n%d %d", last1 - res + 1, last1, last2 - res + 1, last2);
}