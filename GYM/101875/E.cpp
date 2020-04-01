#include <bits/stdc++.h>
using namespace std;

const int N = 455;
const int oo = 1e9 + 7;

char s[N];
int l, k, n, a[N], f[N][N];

int cost(int cnt, int group) {
	// cerr << "cost " << cnt << " " << group << "\n";
	// if (cnt % group == 0) {
	// 	int cnt1 = cnt / group;
	// 	return cnt * (cnt + 1) / 2 * group;
	// }
	int cnt1 = cnt % group;
	int cnt2 = group - cnt1;
	int amount2 = cnt / group;
	int amount1 = amount2 + 1;
	// cerr << cnt1 << " " << cnt2 << " " << amount1 << " " << amount2 << "\n";
	return amount1 * (amount1 + 1) / 2 * cnt1 + amount2 * (amount2 + 1) / 2 * cnt2;
}

int main() {
	// freopen("E.inp", "r", stdin);
	// freopen("E.out", "w", stdout);
	scanf("%d%d %s", &l, &k, s);
	int tmp = 0, cnt1 = 0;
	for (int i = 0; i < l; ++i) {
		if (s[i] == '1') {
			tmp ++;
			cnt1 ++;
		} else if (s[i] == '0' && tmp > 0) {
			a[++n] = tmp;
			tmp = 0;
		}
	}
	if (tmp > 0) {
		a[++n] = tmp;
	}
	// for (int i = 1; i <= n; ++i) cerr << a[i] << " "; cerr << "\n";

	for (int j = 1; j <= cnt1; ++j) f[0][j] = oo;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= cnt1; ++j) {
			f[i][j] = oo;
			for (int k = 0; k <= min(a[i], j); ++k) {
				f[i][j] = min(f[i][j], f[i - 1][j - k] + cost(a[i] - k, k + 1));
			}
			// cerr << "f " << i << " " << j << " " << f[i][j] << "\n";
		}
	}
	for (int j = 0; j <= cnt1; ++j) {
		if (f[n][j] <= k) {
			printf("%d\n", j);
			exit(0);
		}
	}
}