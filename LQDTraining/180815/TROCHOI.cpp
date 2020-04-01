#include <bits/stdc++.h>
using namespace std;

#define task "TROCHOI"

const int N = 1e6 + 5;

int n, a[N];
long long f[N][2];

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		f[i][0] = max(f[i-1][0], f[i-1][1] + a[i]);
		f[i][1] = max(f[i-1][1], f[i-1][0] - a[i]);
	}
	printf("%lld\n", max(f[n][0], f[n][1]));
}