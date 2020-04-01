#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, x, c, a[N];

int main() {
	freopen("ANIMALS.inp", "r", stdin);
	freopen("ANIMALS.out", "w", stdout);
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &c);
		a[i] = c * (n - i + 1);
	}
	sort(a + 1, a + n + 1);
	int res = 0;
	for (int i = 1; i <= n; ++ i) {
		if (x - a[i] >= 0) {
			x -= a[i];
			res ++;
		} else break;
	}
	printf("%d\n", res);
}
