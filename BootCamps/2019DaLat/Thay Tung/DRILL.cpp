#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
long long a[N], b[N], res;

long long calc() {
	for (int i = 1; i <= n; ++ i) {
		b[i] = a[i];
	}
	nth_element(b + 1, b + (n + 1) / 2, b + n + 1);
	long long h = b[(n + 1) / 2];
	cerr << h << "\n";
	long long res = 0;
	for (int i = 1; i <= n; ++ i) {
		res += abs(b[i] - h);
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lld", &a[i]);
	}
	res = calc();
	for (int i = 1; i <= n; i += 2) a[i] -= k;
	res = min(res, calc());
	for (int i = 1; i <= n; i += 2) a[i] += 2 * k;
	res = min(res, calc());
	printf("%lld", res);
}