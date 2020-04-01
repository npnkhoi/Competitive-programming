#include <bits/stdc++.h>
using namespace std;

const int N = 83, M = 1e5 + 3, oo = 1e9 + 7;

int n, m, x[N], s[N], p[N], min_e, max_e, f[N][M];

int calc(int x, int y) {
	// cerr << "calc  " << x << ' ' << y << '\n';
	// s[]
	return p[x] + y;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> x[i] >> s[i];
	}
	for (int j = 1; j <= m; ++ j) f[0][j] = oo;

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			// cerr << i << ' ' << j << '\n';
			min_e = max(0, j - (x[i] + s[i]));
			max_e = max(0, x[i] - (1 + s[i]));
			// cerr << "e's: " << min_e << ' ' << max_e << '\n';
			if (min_e > max_e) f[i][j] = min_e;
			else f[i][j] = calc(x[i]-s[i]-min_e-1, x[i]-s[i]-1);
			cerr << i << ' ' << j << ' ' << f[i][j] << '\n';

			p[j] = min(p[j] - 1, p[j - 1] + f[i][j] - j);
		}
	}
	cout << f[n][m];
}