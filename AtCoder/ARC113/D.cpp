#include <bits/stdc++.h>
using namespace std;

const long long md = 998244353;

long long getExp(long long a, long long n) {
	if (n == 0) return 1;
	long long res = getExp(a, n / 2);
	res = res * res % md;
	if (n % 2) res = res * a % md;
	return res;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	// if (m == 1 && n == 1) {
	// 	cout << k;
	// 	return 0;
	// }

	long long res = 0;
	
	if (n == 1 || m == 1) {
		m = max(m, n);
		for (int x = 1; x <= k; ++ x) {
			res = (res + (getExp(k - x + 1, m) - getExp(k - x, m) + md)) % md;
		}
	} else {
		for (int x = 1; x <= k; ++ x) {
			res = (res + getExp(x, n) * (getExp(k - x + 1, m) - getExp(k - x, m) + md)) % md;
		}
	}
	cout << res;
}