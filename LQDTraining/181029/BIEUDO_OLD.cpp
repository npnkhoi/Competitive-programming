#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long oo = 1e18;

int n, a[N], b[N];
long long res = oo;

int main() {
	freopen("BIEUDO.inp", "r", stdin);
	freopen("BIEUDO.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++ i) {
		int top = max(i, n - i + 1);
		// cerr << top << "\n";
		for (int j = 1; j <= n; ++ j) b[j] = top - abs(i - j) - a[j];
		// for (int j = 1; j <= n; ++ j) cerr << b[j] << " "; cerr << "\n";
		sort(b + 1, b + n + 1);
		long long sum = 0;
		int tmp = (b[(n + 1)/2] < 0 ? b[(n + 1)/2] : 0);
		for (int j = 1; j <= n; ++ j) sum += abs(b[j] - tmp);
		res = min(res, sum);
		// cerr << res << "\n";
	}
	printf("%lld", res);
}