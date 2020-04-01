#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int tc, n, a[N];
long long s[N]; 

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", &a[i]);
		}
		// sort(a + 2, a + n + 1);
		for (int i = 1; i <= n; ++ i) {
			s[i] = s[i - 1] + a[i];
		}
		long long known = 1;
		int counter = 0;
		while (known < n) {
			++ counter;
			known += s[known];
		}
		printf("%d\n", counter);
	}
}