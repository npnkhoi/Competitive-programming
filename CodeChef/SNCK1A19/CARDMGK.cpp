#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int tc, n, a[N];

int downPoint(int l, int r) {
	for (int i = l + 1; i <= r; ++ i) {
		if (a[i - 1] > a[i]) return i;
	}
	return -1;
}

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
		int pos = downPoint(1, n);
		if (pos == -1)
			printf("YES\n");
		else if (downPoint(1, pos - 1) == -1 && downPoint(pos, n) == -1 && a[n] <= a[1])
			printf("YES\n");
		else printf("NO\n");
	}
}