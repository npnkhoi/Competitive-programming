#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, a[N], maxA;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		maxA = max(maxA, a[i]);
	}
	for (int k = maxA; ; ++ k) {;
		int diff = 0;
		for (int i = 1; i <= n; ++ i) {
			diff += k - 2 * a[i];
		}
		if (diff > 0) {
			printf("%d", k);
			exit(0);
		}
	}
}