#include <bits/stdc++.h>
using namespace std;

long long f(long long n, long long i) {
	if (i % 2) return (i + 1) / 2;
	else return (n + 1) / 2 + f(n / 2, i / 2);
}

int main() {
	long long n, q, i;
	scanf("%lld%d", &n, &q);
	while (q --) {
		scanf("%lld", &i);
		printf("%lld\n", f(n, i));
	}
}