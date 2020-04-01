#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, a[N];
long long s[N], res;

long long sum(int l, int r) {
	return s[r] - s[l-1];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] + a[i];
	}
	res = 0;
	int l, r = n + 1;
	for (int l = 1; l < r; ++ l) {
		while (sum(1, l) > sum(r, n) && r - 1 > l) r --;
		if (sum(1, l) == sum(r, n)) {
			res = sum(1, l);
		}
	}
	printf("%lld", res);
}