#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int m, n, k;
vector<vector<int> > a;
int f[N], cnt[30];

void input() {
	freopen("PALMATRIX.inp", "r", stdin);
	freopen("PALMATRIX.out", "w", stdout);
	char ch;
	scanf("%d%d%d", &m, &n, &k);
	a.resize(m + 2);
	for (int i = 1; i <= m; ++ i) a[i].resize(n + 2);
	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			scanf(" %c", &ch);
			a[i][j] = ch - 'a';
		}
	}
}

int calc(int a, int b, int c, int d) {
	cnt[a] ++;
	cnt[b] ++;
	cnt[c] ++;
	cnt[d] ++;
	int res = 4 - max(max(cnt[a], cnt[b]), max(cnt[c], cnt[d]));
	cnt[a] = cnt[b] = cnt[c] = cnt[d] = 0;
	return res;
}

int getMin(int x) {
	int res = 0;
	for (int i = 1; x > 0; ++ i) {
		res += f[i];
		x -= 2;
	}
	return res;
}

void solve() {
	int res1 = 0, res2 = 0;
	int p = n / 2;

	// calculate res1; f[] -> res2
	for (int j = 1; j <= p; ++ j) {
		int tmp1 = 0, tmp2 = 0;
		// col j is not palin
		for (int i = 1; i <= m; ++ i) {
			tmp1 += a[i][j] != a[i][n-j+1];
		}
		// col j is palin
		for (int i = 1; i <= m / 2; ++ i) {
			tmp2 += calc(a[i][j], a[i][n - j + 1], a[m - i + 1][j], a[m - i + 1][n - j + 1]);
		}
		if (m % 2) tmp2 += a[m / 2 + 1][j] != a[m / 2 + 1][n - j + 1];

		res1 += tmp1;
		f[j] = tmp2 - tmp1;
	}

	sort(f + 1, f + p + 1);
	res2 = getMin(k);

	// middle column
	if (n % 2) {
		int tmp2 = 0;
		for (int i = 1; i <= m / 2; ++ i) {
			tmp2 += a[i][p] != a[m - i + 1][p];
		}
		res2 = min(res2, getMin(k - 1) + tmp2);
	}
	printf("%d\n", res1 + res2);
}

int main() {
	input();
	// if (m == 1) sub1();
	// else if (m == 10 && n == 10) sub2();
	solve();
}