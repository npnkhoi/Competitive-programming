#include <bits/stdc++.h>
using namespace std;

const int VAL = 1e6 + 5;

int tc, period, n, val, maxVal, head, last;

int main() {
	scanf("%d", &tc);
	for (int iTest = 1; iTest <= tc; ++iTest) {
		period = 0;
		maxVal = -1;

		scanf("%d", &n);

		last = n + 1;

		for (int i = 1; i <= n; ++i) {
			scanf("%d", &val);
			if (val == -1) continue;
			// i - head = val - 1
			maxVal = max(maxVal, val);
			head = i - val + 1;
			if (last != n + 1) {
				period = __gcd(period, abs(head - last));
			}
			last = head;
		}
		if (period == 0) printf("inf\n");
		else if (period < maxVal) printf("impossible\n");
		else printf("%d\n", period);
	}
}