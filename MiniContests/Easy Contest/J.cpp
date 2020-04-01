#include <bits/stdc++.h>
using namespace std;

const int N = 15e4 + 5;

int n, k, a[N], res;
long long s, minS = 1e18;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		s += a[i];
		if (i > k) s -= a[i-k];
		if (i >= k && s < minS) {
			minS = s;
			res = i - k + 1;
		}
	}
	printf("%d", res);
}