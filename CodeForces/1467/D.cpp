#include <bits/stdc++.h>
using namespace std;

const int N = 5005, md = 1e9 + 7;

int n, k, q;
long long a[N], g[N][N], f[N], res;

void dp() {
	for (int i = 1; i <= n; ++ i) {
		g[i][0] = 1;
	}
	for (int len = 1; len <= k; ++ len) {
		for (int cell = 1; cell <= n; ++ cell) {
			g[cell][len] = (g[cell - 1][len - 1] + g[cell + 1][len - 1]) % md;
		}
	}

	for (int u = 1; u <= n; ++ u) {
		f[u] = 0;
		for (int t = 0; t <= k; ++ t) {
			f[u] = (f[u] + g[u][t] * g[u][k - t] % md) % md; 
		}
		// cerr << f[u] << ' ';
	}
}

int main() {
	cin >> n >> k >> q;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}

	dp();

	for (int i = 1; i <= n; ++ i) {
		res = (res + f[i] * a[i] % md) % md;
	}

	for (int i = 0; i < q; ++ i) {
		int cell, val;
		cin >> cell >> val;
		res = (res + (md + val - a[cell]) % md * f[cell] % md) % md;
		a[cell] = val;
		cout << res << '\n';
	}
}