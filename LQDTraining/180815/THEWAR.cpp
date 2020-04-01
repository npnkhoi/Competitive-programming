#include <bits/stdc++.h>
using namespace std;
#define task "THEWAR"
const int N = 2e5 + 5;
int n, q, a[N];
long long s[N];

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] + a[i];
	}
	int idx = 1;
	long long arrow = 0, addArrow;
	for (int i = 1; i <= q; i ++) {
		scanf("%lld", &addArrow);
		arrow += addArrow;
		int lo = idx - 1, hi = n, mid, bs = lo;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (s[mid] - s[idx - 1] <= arrow) {
				bs = mid;
				lo = mid + 1;
			} else hi = mid - 1;
		}
		arrow -= s[bs] - s[idx - 1];
		if (bs == n) {
			printf("%d\n", n);
			idx = 1;
			arrow = 0;
		} else {
			printf("%d\n", n - bs);
			idx = bs + 1;
		}
		//cerr << "idx: " << idx << "\n";
	}
}