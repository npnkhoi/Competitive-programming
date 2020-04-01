#include <bits/stdc++.h>
using namespace std;

int tc, n;

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	while (tc --) {
		cin >> n;
		long long su = 0, xo = 0;
		while (n --) {
			int x;
			cin >> x;
			su += x;
			xo ^= x;
		}
		if (su == 2 * xo) {
			cout << "0\n\n";
			continue;
		}

		long long x = 0, y = 0;
		if ((su > 2 * xo) || (su % 2 == 1)) {
			x = (1LL << 50) + (su % 2);
		}
		y = (2 * (xo ^ x) -(su + x)) / 2;
		cout << "3\n" << x << ' ' << y << ' ' << y << '\n';
		// cerr << "check: " << (su + x + y + y) - 2 * (xo ^ x ^ y ^ y) << '\n';
	}
}