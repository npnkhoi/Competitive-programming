#include <bits/stdc++.h>
using namespace std;



int main() {
	int tc, n, k, x, y;
	cin >> tc;
	while (tc --) {
		cin >> n >> k >> x >> y;
		long long l = 0, r = 1LL * n * k, mid, res;
		while (l < r) {
			mid = (l + r) / 2;
			if (count_bounce(mid) >= k) {
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		int x_delta = res % (2 * n);
		if (x + x_delta >= n) {
			x_delta = x + x_delta - n;
			x = n - x_delta;
		} else {
			x += x_delta;
		}

		int y_delta = res % (2 * n);
		if (y + y_delta >= n) {
			y_delta = y + y_delta - n;
			y = n - y_delta;
		} else {
			y += y_delta;
		}

		cout << x << y << '\n';
	}
}