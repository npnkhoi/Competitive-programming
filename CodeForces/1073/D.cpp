#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, a[N], cur;
long long budget, res, ft[N];

void update(int i, int val) {
	for (; i <= n; i += i & (-i)) ft[i] += val;
}

long long get(int i) {
	if (i == 0) return 0;
	long long res = 0;
	for (; i; i -= i & (-i)) res += ft[i];
	return res;
}

int main() {
	scanf("%d%lld", &n, &budget);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		update(i, a[i]);
	}
	cur = n;
	while (cur > 0) {
		int l = 0, r = n, mid, bs = l;
		while (l <= r) {
			// cerr << l << " " << r << "\n";
			mid = (l + r) / 2;
			if (get(mid) <= budget) {
				bs = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		// cerr << "max: " << bs << "\n";
		if (bs == n) {
			long long s = get(n);
			res += budget / s * cur;
			budget %= s;
			// cerr << "update: " << s << endl;
 		} else {
			update(bs + 1, - a[bs + 1]);
			cur --;
		}
		// cerr << "end: " << res << " " << budget << "\n";
	}
	printf("%lld", res);
}