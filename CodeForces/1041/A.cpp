#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	printf("%d\n", max(a[n] - a[1] + 1 - n, 0));
}