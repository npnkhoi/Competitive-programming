#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const long long oo = 1e18;

int l1, l2, l3, c1, c2, c3;
int n, s, t;
long long a[N], f[N];

int main() {
	freopen("RTICKET.inp", "r", stdin);
	freopen("RTICKET.out", "w", stdout);
	scanf("%d%d%d", &l1, &l2, &l3);
	scanf("%d%d%d", &c1, &c2, &c3);
	scanf("%d%d%d", &n, &s, &t);
	for (int i = 2; i <= n; ++ i) {
		scanf("%lld", &a[i]);
	}

	bool rev;
	if (s > t) swap(s, t), rev = 1;
	else rev = 0;
	for (int i = s; i <= t; ++ i) {
		a[i - s + 1] = a[i];
	}
	n = t - s + 1;
	if (rev) {
		for (int i = 1; i <= n/2; ++ i) {
			swap(a[i], a[n - i + 1]);
		}
		for (int i = 2; i <= n; ++ i) {
			a[i] = abs(a[1] - a[i]);
		}
		a[1] = 0;
	}

	// for (int i = 0; i <= n; ++ i) {
	// 	cerr << a[i] << " ";
	// }
	// cerr << "\n";

	f[1] = 0;
	for (int i = 2; i <= n; ++ i) {
		f[i] = oo;
		int p;
		p = lower_bound(a + 1, a + i + 1, a[i] - l1) - a;
		if (p < i) f[i] = min(f[i], f[p] + c1);
		p = lower_bound(a + 1, a + i + 1, a[i] - l2) - a;
		if (p < i) f[i] = min(f[i], f[p] + c2);
		p = lower_bound(a + 1, a + i + 1, a[i] - l3) - a;
		if (p < i) f[i] = min(f[i], f[p] + c3);
	}
	printf("%lld", f[n]);
}