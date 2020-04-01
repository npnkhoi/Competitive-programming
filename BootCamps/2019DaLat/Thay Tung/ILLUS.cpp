#include <bits/stdc++.h>
using namespace std;

long long calc(long long x) {
	return x * (x + 1) / 2;
}

long long calc(long long l, long long r) {
	return calc(r) - calc(l - 1);
}

int main() {
	long long k, s, ilp, lp, rp, t;
	scanf("%lld%lld", &k, &s);
	ilp = 0;
	for (long long n = k + 1; ; ++ n) {
		t = calc(k + 1, n);
		lp = t - calc(n - ilp + 1, n);
		rp = t - calc(k + 1, k + ilp);
		if (lp <= s && s <= rp) break;
		if (s < lp) ilp ++, n --;
	}
	printf("%lld\n", ilp + k);
}