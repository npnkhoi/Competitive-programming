#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;
const int N = 5e5 + 5;

int n, a[N], neg, pos, minVal;
long long sum;

int main() {
	minVal = oo;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		if (a[i] < 0) ++ neg;
		else if (a[i] > 0) ++ pos;
		minVal = min(minVal, abs(a[i]));
		sum += abs(a[i]);
	}	
	if (n == 1) {
		printf("%d\n", a[1]);
	} else if (neg == n || pos == n) {
		printf("%lld\n", sum - 2 * minVal);
	} else printf("%lld\n", sum);
}