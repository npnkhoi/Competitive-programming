#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N], res;
long long s;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i) {
		if (s <= a[i]) {
			res ++;
			s += a[i];
		}
	}
	printf("%d", res);
}
