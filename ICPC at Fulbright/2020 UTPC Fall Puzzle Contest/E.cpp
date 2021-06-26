#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc --) {
		long long a, b, c, d; cin >> a >> b >> c >> d;
		long long x = abs(a - c), y = abs(b - d), r = abs(x - y);
		cout << min(x, y) * 2 + r / 2 * 4 + r % 2 << '\n';
	}
}