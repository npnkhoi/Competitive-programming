#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
long long x[N], y[N], s, i, b;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%lld%lld", &x[i], &y[i]);
	for (int i = 1; i <= n; ++ i) {
		int j = (i == n ? 1 : i + 1);
		s += x[i] * y[j] - x[j] * y[i];
		b += __gcd(abs(x[i] - x[j]), abs(y[i] - y[j]));
	}
	s = abs(s);
	// cerr << s - b + 1 << "\n";
	i = (s - b + 2) / 2;
	printf("%lld", b + i);
}