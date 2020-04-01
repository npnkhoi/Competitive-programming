#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

#define task "Q07"

int n, a[N], f[N], res;

bool check(int val) {
	int lo = 1, hi = 100000, mid, bs = lo;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (1LL * mid * (mid + 1) / 2 <= val) {
			bs = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}	
	return 1LL * bs * (bs + 1) / 2 == val;
}
int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		if (check(a[i])) {
			if (i > 1 && a[i] >= a[i-1]) {
				f[i] = f[i-1] + 1;
			} else f[i] = 1;
		}
		//cerr << f[i] << " ";
		res = max(res, f[i]);
	}	
	printf("%d\n", res);
}