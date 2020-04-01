#include <bits/stdc++.h>
using namespace std;

int n;
long long l, r;

long long calc(long long u, long long v) {
	// cerr << u << " " << v << "\n";
	if (v < l || r < u) return -1;
	if (l <= u && v <= r) {
		return v;
	}
	long long x = calc(u, (u + v) / 2);
	long long y = calc((u + v) / 2 + 1, v);
	if (x == -1) return y;
	if (y == -1) return x;
	if (__builtin_popcountll(x) >= __builtin_popcountll(y)) return x;
	return y;
}

int main() {
	// cerr << (1LL << 30) << "\n";
	scanf("%d", &n);
	while (n --) {
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", calc(0, (1LL << 60) - 1));
	}
}