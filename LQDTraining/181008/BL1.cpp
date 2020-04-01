#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k;
int a[N], b[N], s[N], cnt[N];
long long res;

int main() {
	freopen("BL1.inp", "r", stdin);
	freopen("BL1.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int m = 0, tmp = 0;
	for (int i = 1; i <= n; ++ i) {
		tmp ++;
		if ((i < n && a[i] != a[i + 1]) || i == n) {
			b[++m] = a[i];
			s[m] = s[m - 1] + tmp;
			cnt[m] = tmp;
			tmp = 0;
		}
	}	
	// for (int i = 1; i <= m; ++ i) {
	// 	cerr << b[i] << " " << s[i] << " " << cnt[i] << "\n"; 
	// }
	for (int i = 1; i <= m; ++ i) {
		int p = lower_bound(b + 1, b + m + 1, min(k - b[i] + 1, b[i])) - b - 1;
		// cerr << i << " " << p << "\n";
		res += 1LL * cnt[i] * s[p];
		// cerr << res << "\n";
		if (2 * b[i] <= k) {
			res += 1LL * cnt[i] * (cnt[i] - 1) / 2;
		}
	}
	printf("%lld", res);
}
