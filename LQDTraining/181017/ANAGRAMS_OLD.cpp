#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int oo = 1e9 + 7;
const int MASK = (1 << 27) + 2;

char s[N], t[N];
int n, a[N][N], dp[MASK];

void sub1() {
	// cerr << s+1 << " " << t+1 << "\n";
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			a[i][j] = t[j] - s[i];
			if (a[i][j] < 0) a[i][j] += 26;
		}
	}
	// cerr << "ok\n";
	for (int mask = 1; mask < (1 << n); ++ mask) {
		dp[mask] = oo;
		int row = __builtin_popcount(mask);
		for (int j = 0; j < n; ++ j) {
			if (mask & (1 << j)) {
				dp[mask] = min(dp[mask], dp[mask ^ (1 << j)] + a[row][j + 1]);
			}
		}
	}
	printf("%d\n", dp[(1 << n) - 1]);
}

void sub2() {

}

int main() {
	freopen("ANAGRAMS.inp", "r", stdin);
	freopen("ANAGRAMS.out", "w", stdout);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	n = strlen(s + 1);
	// cerr << "ok\n";
	if (n <= 50) sub1();
	else sub2();
}