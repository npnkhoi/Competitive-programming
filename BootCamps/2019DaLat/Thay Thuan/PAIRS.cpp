#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long md = 1e9 + 7;

int n, a[N], b[N], s[N];
long long res;

void readInt(int &x) {
	int c;
	do c = getchar(); while (c < '0' || '9' < c);
	x = c - '0';
	while (1) {
		c = getchar();
		if (c < '0' || '9' < c) break;
		x = 10 * x + c - '0';
	}
}

int Exp10(int x) {
	int res = 1;
	while (x) {
		res *= 10;
		x /= 10;
	}
	return res;
}

int main() {

	// scanf("%d", &n);
	readInt(n);
	for (int i = 1; i <= n; ++ i) {
		// scanf("%d", &a[i]);
		readInt(a[i]);
		b[i] = Exp10(a[i]);
		s[i] = (s[i-1] + b[i]) % md;
	}
	for (int i = 1; i <= n; ++ i) {
		res = (res + (long long) a[i] * (n - 1) + (long long) (s[n] - b[i]) * a[i] + md * md) % md;
	}
	printf("%lld", res);
}