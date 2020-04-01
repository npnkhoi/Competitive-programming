#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, md = 998244353;

int n, p[N];

long long Exp(int a, int n) {
	if (n == 0) return 1;
	long long res = Exp(a, n / 2);
	res = res * res % md;
	if (n%2) res = res * a % md;
	return res;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> p[i];
	}
	long long res = 1;
	for (int i = 1; i <= n-2; ++i) {
		long long tmp = (100 * Exp(p[i], md - 2) + 1) % md;
		res = res * tmp % md;
	}
	res = res * 100 % md;
	res = res * Exp(p[n-1], md-2) % md;
	res = (res + 1) % md;
	res = res * 100 % md;
	res = res * Exp(p[n], md - 2) % md;
	cout << res;
}