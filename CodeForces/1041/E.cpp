#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, a[N], ans[N];
set<int> rest;

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u > v) {
			swap(u, v);
		}
		if (v < n || u == n) {
			printf("NO\n");
			exit(0);
		}
		a[i] = u;
		rest.insert(i);
	}
	sort(a + 1, a + n);

	int curMax = 0;
	for (int i = 1; i < n; ++i) {
		curMax = max(curMax, *rest.begin());
		if (curMax == a[i]) {
			ans[i] = *rest.begin();
			rest.erase(rest.begin());
		} else if (curMax < a[i]) {
			ans[i] = a[i];
			rest.erase(a[i]);
			curMax = a[i];
		} else {
			printf("NO\n");
			exit(0);
		}
	}
	ans[n] = n;
	printf("YES\n");
	for (int i = 1; i < n; ++i) {
		printf("%d %d\n", ans[i], ans[i + 1]);
	}
}