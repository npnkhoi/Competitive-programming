#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int md = 1e9 + 7;

int n, a[N], b[N], f[N]; 

void sub1() {
	long long minCost = 1LL << 60;
	int res = 0;
	do {
		long long tmp = 0;
		for (int i = 1; i <= n; ++ i) {
			tmp += abs(a[i] - b[i]);
		}
		if (tmp < minCost) {
			minCost = tmp;
			res = 1;
		} else if (tmp == minCost) {
			res ++;
		}
	} while (next_permutation(b + 1, b + n + 1));
	printf("%d", res);
}

void sub3() {
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; ++ i) {
		f[i] = f[i - 1];
		if (b[i] < a[i - 1] || a[i] < b[i- 1]) f[i] = (f[i] + f[i - 2]) % md;
	}
	printf("%d", f[n]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &b[i]);
	}
	sort(b + 1, b + n + 1);
	if (n <= 10) sub1();
	else sub3();
}