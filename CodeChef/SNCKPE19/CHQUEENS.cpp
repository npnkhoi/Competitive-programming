#include <bits/stdc++.h>
using namespace std;

int f(int n) {
	return n * (n - 1) / 2;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc --) {
		int n, m, x, y;
		scanf("%d%d%d%d", &m, &n, &x, &y);
		if (m < n) {
			swap(m, n);
			swap(x, y);
		}
		// int res = 0;
		// // hor, ver
		// res += m * n * (m + n - 2) / 2;
		// // diag
		// res += (m - n + 1) * n * (n - 1); // x2
		// for (int i = 2; i <= n - 1; ++ i) {
		// 	res += 4 * f(i); // x4
		// }
		// cerr << res << "\n";
		// // res -= a * b + c * d + min(a, c) * min(b, d) + min(a, d) * min(b, c);
		// // res -= f(a + b);
		// // res -= f(c + d);
		// // res -= f(min(a, c) + min(b, d));
		// // res -= f(min(a, d) + min(b, c));
		// res -= a * b + c * d + min(a, c) * min(b, d) + min(a, d) * min(b, c);
		// res -= a + b + c + d + min(a, c) + min(b, d) + min(a, d) + min(b, c);
		// cerr << res << "\n";
		// // res -= 1;
		// res = m * n * (m * n - 1) / 2 - res;

		int res1 = m * n * (m * n - 1);

		int res2 = m * n * (m + n - 2) + 2 * (m - n + 1) * n * (n - 1);
		for (int i = 2; i <= n - 1; ++ i) res2 += 4 * i * (i - 1);

		int a = x - 1, b = m - x, c = y - 1, d = n - y;

		int res3 = 2 * (a * b + a + b);  
		res3 += 2 * (c * d + c + d);
		res3 += 2 * (min(a, c) * min(b, d) + min(a, c) + min(b, d));
		res3 += 2 * (min(a, d) * min(b, c) + min(a, d) + min(b, c));

		cerr << res1 << " " << res2 << " " << res3 << "\n";

		printf("%d\n", res1 - res2 + res3);
	}
}