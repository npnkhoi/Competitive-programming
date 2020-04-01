#include <bits/stdc++.h>
using namespace std;

int tc, l, r;

long long calc(int x) {
	if (x == 0) return 0;
	long long y = (x + 1) / 2;
	return y * y + calc(x / 2);
}

int main() {
	freopen("ODS.inp", "r", stdin);
	freopen("ODS.out", "w", stdout);
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d", &l, &r);
		printf("%lld\n", calc(r) - calc(l - 1));
	}
}