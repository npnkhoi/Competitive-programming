#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N];
long long scoreA, scoreB, res;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		scoreA += a[i];
	}
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i + n]);
		scoreB += a[i + n];
	}
	sort(a + 1, a + 2 * n + 1);
	res = scoreA - scoreB;
	for (int i = 1; i <= 2 * n; ++ i) {
		if (i % 2) {
			res -= a[i];
		} else {
			res += a[i];
		}
	}
	printf("%lld\n", res / 2);
}