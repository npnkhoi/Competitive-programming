#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	if (n % 2 == 0) {
		printf("%lld\n", n / 2);
		return 0;
	}
	for (int i = 2; i <= sqrt(n); ++ i) {
		if (n % i == 0) {
			n -= i;
			printf("%lld\n", n / 2 + 1);
			return 0;
		}
	}
	printf("1\n");
}