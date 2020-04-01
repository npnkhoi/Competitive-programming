#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, k;
long long f[N][2];
long long x[N], y[N];

long long require(long long x) {
	return (x + k - 1) / k - 1;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i) scanf("%lld", &x[i]);
	for (int i = 1; i <= n; ++ i) scanf("%lld", &y[i]);
	// f[0][0] = f[0][1] = 0;
	for (int i = 1; i <= n; ++ i) {
		f[i][0] = f[i][1] = k + 1;
		int a = f[i - 1][0], b = f[i - 1][1];

		if (x[i] - 1 >= require(y[i]) && a <= k) {
			f[i][0] = min(f[i][0], max(1LL, x[i] - ((y[i] - 1) * k + k - a)));
		}
		// cerr << f[i][0] << " " << f[i][1] << "\n";
		if (x[i] - 1 >= require(y[i] + b) && b <= k) {
			f[i][0] = min(f[i][0], max(1LL, x[i] - (y[i] * k)));
		}
		// cerr << f[i][0] << " " << f[i][1] << "\n";

		if (y[i] - 1 >= require(x[i]) && b <= k) {
			f[i][1] = min(f[i][1], max(1LL, y[i] - ((x[i] - 1) * k + k - b)));
		}
		// cerr << f[i][0] << " " << f[i][1] << "\n";
		if (y[i] - 1 >= require(x[i] + a) && a <= k) {
			f[i][1] = min(f[i][1], max(1LL, y[i] - (x[i] * k)));
		}
		// cerr << f[i][0] << " " << f[i][1] << "\n";
		// cerr << "\n";
	}
	if (f[n][0] <= k || f[n][1] <= k) printf("YES\n");
	else printf("NO\n");
}