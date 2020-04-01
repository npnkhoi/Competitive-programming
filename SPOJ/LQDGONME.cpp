#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 15;

int n, m, res;
int a[M][N], pos[N][M], f[N];

bool pre(int x, int y) {
	for (int i = 1; i <= m; i ++) {
		if (pos[x][i] > pos[y][i]) return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			scanf("%d", &a[i][j]);
			pos[a[i][j]][i] = j; 
		}
	}
	for (int i = 1; i <= n; i ++) {
		f[i] = 1;
		for (int j = 1; j < i; j ++) {
			if (pre(a[1][j], a[1][i])) {
				f[i] = max(f[i], f[j] + 1);
				//cerr << j << " " << i << " " << f[i] << "\n";
			}
		}
		res = max(res, f[i]);
	}
	printf("%d", res);
}