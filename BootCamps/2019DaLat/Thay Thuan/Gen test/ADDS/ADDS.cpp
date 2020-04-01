#include <bits/stdc++.h>
using namespace std;

long long a, b, m;

long long calc(int n) {
	long long x = n, y = n + 1, z = 2 * n + 1;

	if (x % 3 == 0) x /= 3;
	else if (y % 3 == 0) y /= 3;
	else z /= 3;

	if (x % 2 == 0) x /= 2;
	else if (y % 2 == 0) y /= 2;
	else z /= 2;

	return x * y % m * z % m;
}

int main() {
	scanf("%lld%lld%lld", &a, &b, &m);
	printf("%lld", (calc(b) - calc(a - 1) + m) % m);
}