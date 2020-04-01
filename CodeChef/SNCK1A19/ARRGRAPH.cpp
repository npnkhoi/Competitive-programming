#include <bits/stdc++.h>
using namespace std;

const int N = 52;

int tc, n, a[N], num[N], counter, maxSz, sz, head, keep;

void dfs(int u) {
	num[u] = counter;
	sz ++;
	for (int v = 1; v <= n; ++ v) {
		if (num[v] == 0 && __gcd(a[u], a[v]) == 1) {
			dfs(v);
		}
	}
}

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
		memset(num, 0, sizeof num);
		counter = maxSz = 0;
		for (int i = 1; i <= n; ++ i) {
			if (num[i] == 0) {
				sz = 0;
				counter ++;
				dfs(i);
			}
			if (sz > maxSz) {
				maxSz = sz;
				keep = counter;
				head = a[i];
			}
		}
		int val = 2;
		while (__gcd(val, head) != 1) ++ val;

		printf("%d\n", n - maxSz);
		for (int i = 1; i <= n; ++ i) {
			if (num[i] != keep) {
				printf("%d ", val);
			} else {
				printf("%d ", a[i]);
			}
		}
		printf("\n");
	}
}