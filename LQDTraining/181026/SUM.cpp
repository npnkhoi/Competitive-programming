#include <bits/stdc++.h>
using namespace std;

const int N =  1e5 + 5;

int n, a[N];
long long s[N], l[N], r[N], res;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		l[i] = max(l[i - 1], - s[i]);
	}
	for (int i = n; i >= 1; -- i) {
		r[i] = max(r[i + 1], - s[n] + s[i - 1]);
	}
	for (int i = 1; i <= n; ++ i) {
		// cerr << l[i] << " " << r[i] << "\n";
		res = max(res, s[n] + 2 * (l[i] + r[i + 1]));
	}
	printf("%lld", res);
}