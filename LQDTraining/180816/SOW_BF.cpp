#include <bits/stdc++.h>
using namespace std;

#define task "SOW"

const int N_BIT = 64;

long long a, b, res;

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".ans", "w", stdout);
	scanf("%lld %lld", &a, &b);
	for (long long i = a; i <= b; i ++) {
		res += i & -i;
	}
	printf("%lld", res);
}