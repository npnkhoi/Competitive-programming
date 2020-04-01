#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 13;

int n, m, a[M][N], pos[M][N], f[N];

bool match(int x, int y) {
	for (int i = 1; i <= m; ++ i) {
		if (pos[i][y] - pos[i][x] != 1) return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf("%d", &a[i][j]);
			pos[i][a[i][j]] = j;
		}
	}
	f[1] = 1;
	long long res = 1;
	for (int i = 2; i <= n; ++i) {
		if (match(a[1][i-1], a[1][i])) {
			f[i] = f[i-1] + 1;
		} else f[i] = 1;
		res += f[i];
	}
	printf("%lld", res);
}