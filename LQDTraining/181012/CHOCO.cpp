#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];
long long s[N];

int main() {
	freopen("CHOCO.inp", "r", stdin);
	freopen("CHOCO.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	int l = 1, r = n, mid, bs = r;
	while (l <= r) {
		mid = (l + r) / 2;
		if (s[mid] >= (s[n] + 1) / 2) {
			bs = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (s[bs - 1] > s[n] - s[bs]) bs --;
	printf("%d %d", bs, n - bs);
}