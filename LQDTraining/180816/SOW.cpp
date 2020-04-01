#include <bits/stdc++.h>
using namespace std;

#define task "SOW"

const int N_BIT = 64;

long long a, b, f[N_BIT];

long long calc(long long n) {
	long long res = 0;
	for (int i = 0; (1LL << i) <= n; i ++) {
		if ((n & (1LL << i)) > 0) {
			res += f[i];
		}
	}
	return res;
} 

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	f[0] = 1;
	for (int i = 1; (1LL << i) <= 1e15; i ++) {
		f[i] = 2 * f[i-1] + (1LL << (i - 1));
	}
	scanf("%lld %lld", &a, &b);
	printf("%lld", calc(b) - calc(a - 1));
}