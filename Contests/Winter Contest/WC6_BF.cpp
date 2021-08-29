#include <bits/stdc++.h>
using namespace std;
#define task "WC6"
const int N = 55;
int tc, n, m, c, k;
int a[N][N];

int cnt() {
	int res = 0;
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j ++) {
			// cerr << a[i][j] << " ";
			if (a[i][j]) {
				if (i + 1 < m && a[i+1][j]) res ++;
				if (j + 1 < n && a[i][j+1]) res ++;
			}
		}
		// cerr << "\n";
	}
	// cerr << "\n";
	return res;
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".ans", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d%d", &m, &n, &c, &k);
		int res = 0;
		for (int mask = 0; mask < (1 << (m * n)); mask ++) {
			//cerr << mask << "is mask \n";
			if (__builtin_popcount(mask) == c) {
				for (int i = 0; i < m; i ++) {
					for (int j = 0; j < n; j ++) {
						a[i][j] = (mask & (1 << (i * n + j))) > 0;
					}
				}	
				if (cnt() <= k) res ++;
			}
		}
		printf("%d\n", res);
	}
}