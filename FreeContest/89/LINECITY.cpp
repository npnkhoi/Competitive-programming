#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int l, n, a[N], res, pos;

int main() {
	scanf("%d%d", &l, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; ++ i) {
		if ((a[i] - a[i-1]) / 2 > res) {
			res = (a[i] - a[i-1]) / 2;
			pos = (a[i] + a[i - 1]) / 2;
		}
	}
	if (a[1] > res) {
		res = a[1];
		pos = 0;
	}
	if (l - a[n] > res) {
		res = l - a[n];
		pos = l;
	}
	printf("%d", res);
}