#include <bits/stdc++.h>
using namespace std;

int q, l1, l2, l3, l4, r1, r2, r3, r4, y, res;

int main() {
	int K = (int) ceil(sqrt(1e9));
	scanf("%d", &q);
	while (q --) {
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		int res = min(r1 - l1 + 1, r2 - l2 + 1);
		for (int i = res + 1; i <= K; ++ i) {
			if ((l1 + i - 1) / i <= r1 / i && (l2 + i - 1) / i <= r2 / i) {
				res = max(res, i);
			}
		}
		// cerr << res << "\n";
		for (int x = 1; x <= K; ++ x) {
			l3 = (l1 + x - 1) / x;
			r3 = (r1) / x;
			if (r3 == 0) continue;
			y = (l2 + r3 - 1) / r3;
			if (y == 0) continue;
			l4 = (l2 + y - 1) / y;
			r4 = r2 / y;
			if (l3 > r3 || l4 > r4) continue;
			if (l3 <= r4 && r4 <= r3) res = max(res, r4);
			if (l4 <= r3 && r3 <= r4) res = max(res, r3);
			// cerr << x << " " << y << " " << res << "\n";
		}
		printf("%d\n", res);
	}
}