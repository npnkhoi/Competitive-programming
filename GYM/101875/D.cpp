#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, x, y, u, v;
	scanf("%lld%lld%lld%lld%lld", &n, &x, &y, &u, &v);
	long long dist = (abs(u - x) + abs(v - y));
	if (dist == 0) {
		printf("%lld\n", n / 2);
	} else {
		long long tmp = n - dist;
		if (tmp < 0) printf("0\n");
		else printf("%lld\n", tmp / 2 + 1);
	}
}