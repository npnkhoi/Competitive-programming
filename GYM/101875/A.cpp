#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k;
	scanf("%lld%lld", &n, &k);
	long long t = __gcd(n, k);
	printf("%lld", t * (n / t - 1) * k + (t - 1) * (k - 1));
}