#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc, n, d, v, f, c, res;
	scanf("%d", &tc);
	while (tc --) {
		res = 0;
		scanf("%d %d", &n, &d);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &v, &f, &c);
			if ((double) d / v * c <= (double) f) {
				res ++;
			}
		}
		printf("%d\n", res);
	}
}