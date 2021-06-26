#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int q, k;
long long m, n, x1, x2;
long long x[N], y[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n >> k;
	for (int i = 0; i < k; ++i) {
		cin >> x[i] >> y[i];
	}
	cin >> q;
	while (q --) {
		cin >> x1 >> x2;
		int res = 0;
		for (int i = 0; i < k; ++ i) {
			res += (x[i] * m < y[i] * (x2 - x1) + x1 * m) && (y[i] * (x2 - x1) + x1 * m < (x[i] + 1) * m) ||
				(x[i] * m < (y[i] + 1) * (x2 - x1) + x1 * m) && ((y[i] + 1) * (x2 - x1) + x1 * m < (x[i] + 1) * m);
			res += ((y[i] * (x2 - x1) + x1 * m == x[i] * m) && 
				((y[i] + 1) * (x2 - x1) + x1 * m == (x[i] + 1) * m));
		}
		cout << res << '\n';
	}
}