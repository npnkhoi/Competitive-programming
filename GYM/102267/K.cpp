#include <bits/stdc++.h>
using namespace std;

const int N = 22;

int n, a[N];
long long res;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
	for (int mask = 0; mask < (1 << n); ++ mask) {
		int sum = 0;
		for (int i = 0; i < n; ++ i) {
			if (mask >> i & 1) sum |= a[i];
		}
		res += sum;
	}
	printf("%lld", res);
}