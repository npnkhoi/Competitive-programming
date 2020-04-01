#include <bits/stdc++.h>
using namespace std;

int a[22], m, n, s, res;

void backtrack(int x) {
	if (x == n + 1) {
		res += (s == m);
		return;
	}
	for (int y = - 1; y <= 1; ++y) {
		s += y * a[x];
		backtrack(x + 1);
		s -= y * a[x];
	}
}

int main() {
	freopen("BALANCE.inp", "r", stdin);
	freopen("BALANCE.ans", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
	}
	s = 0;
	backtrack(1);
	printf("%d", res);
}