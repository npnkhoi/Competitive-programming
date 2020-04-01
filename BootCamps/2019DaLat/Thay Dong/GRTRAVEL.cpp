#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, din[N];
long long res, tmp;

int main() {
	freopen("GRTRAVEL.inp", "r", stdin);
	freopen("GRTRAVEL.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) din[i] = n - i;
	for (int i = 1; i <= m; ++ i) {
		int u, v;
		scanf("%d%d", &u, &v);
		din[v] ++;
		din[u] --;
	}
	res = 1LL * n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; ++ i) {
		if (din[i] >= 2) tmp += 1LL * din[i] * (din[i] - 1) / 2;
		int x = n - 1 - din[i];
		if (x >= 2) tmp += 1LL * x * (x - 1) / 2;
	}
	res -= tmp / 2;
	printf("%lld\n", res);
}