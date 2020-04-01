#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, a[N], s[N], f[N]; 

int main() {
	freopen("BL4.inp", "r", stdin);
	freopen("BL4.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	f[0] = m;
	for (int i = 1; i <= n; ++ i) {
		f[i] = 0;
		for (int j = i - 1; j >= 0; -- j) {
			if (s[i] - s[j] > m) break;
			f[i] = max(f[i], min(f[j], s[i] - s[j]));
		}
	}
	printf("%d", m - f[n]);
}