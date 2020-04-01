#include <bits/stdc++.h>
using namespace std;

const int N = 13;
const int sh = 11;
const int oo = 1e9 + 7;
const int MASK = (1 << 10) + 5;

int n, res = oo;
int a[N], col[N], diag1[2 * N], diag2[2 * N], dp[MASK];
pair<int, int> pos[N];

void calc() {
	// fill INF
	dp[0] = 0;
	for (int mask = 1; mask < (1 << n); ++ mask) {
		dp[mask] = oo;
		int j = __builtin_popcount(mask);
		for (int i = 1; i <= n; ++ i) {
			if ((mask & (1 << (i - 1))) == 0) continue;
			dp[mask] = min(dp[mask], 
				dp[mask ^ (1 << i - 1)] + max(abs(pos[j].first - i), abs(pos[j].second - a[i])));
		}
	}
	// for (int i = 1; i <= n; ++ i) cerr << a[i] << " ";
	res = min(res, dp[(1 << n) - 1]);
	// cerr << ", " << res << "\n";
}

void brute(int i) {
	if (i == n + 1) {
		calc();
		return;
	}
	for (int j = 1; j <= n; ++ j) {
		if (!col[j] && !diag1[i - j + sh] && !diag2[i + j]) {
			a[i] = j;
			col[j] = 1;
			diag1[i - j + sh] = 1;
			diag2[i + j] = 1;
			brute(i + 1);
			col[j] = 0;
			diag1[i - j + sh] = 0;
			diag2[i + j] = 0;
		}
	}
}

int main() {
	freopen("MQUEEN.inp", "r", stdin);
	freopen("MQUEEN.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		char x, y;
		scanf(" %c %c", &x, &y);
		// cerr << x << y << "\n";
		pos[i] = make_pair(x - 'a' + 1, y - '0');
		// cerr << pos[i].first << " " << pos[i].second << "\n";
	}
	brute(1);
	printf("%d\n", (res == oo ? -1 : res));
}