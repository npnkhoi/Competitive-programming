#include <bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;

long long Exp(long long a, long long x) {
	if (x == 0) return 1;
	long long res = Exp(a, x/2);
	res = res * res % md;
	if (x % 2) res = res * a % md;
	return res;
}

int main() {
	int n, k;
	scanf("%d%d", &k, &n);
	long long res = 1;
	for (int i = 1; i <= n; ++ i) res = res * i % md;
	for (int i = k; i <= n + k - 1; ++ i) res = res * i % md;
	for (int i = 2; i <= n; ++ i) res = res * Exp(i, md - 2) % md;
	printf("%lld", res);
}