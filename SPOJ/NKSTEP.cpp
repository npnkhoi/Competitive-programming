#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

long long f[N];
int tc;

int main() {
	f[0] = 0;
	for (int i = 1; i <= 1e5; i ++) {
		f[i] = f[i-1] + (i + 1) / 2;
	}
	scanf("%d", &tc);
	long long x, y, dist;
	while (tc --) {
		scanf("%lld%lld", &x, &y);
		dist = abs(x - y);
		int lo = 0, hi = 1e5, mid, bs = hi;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			if (f[mid] >= dist) {
				bs = mid;
				hi = mid - 1;
			} else lo = mid + 1;
		}
		printf("%d\n", bs);
	}
}