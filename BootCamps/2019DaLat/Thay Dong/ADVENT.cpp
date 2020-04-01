#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int N = 2005;
const int oo = 1e9 + 7;

int n, d, res;
pair<int, int> a[N];
int s[N], f[N][N];

void input() {
	freopen("ADVENT.inp", "r", stdin);
	freopen("ADVENT.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	scanf("%d", &d);
}

void solve() {
	sort(a + 1, a + n + 1, [](ii a, ii b) {
		return a.first + a.second < b.first + b.second;
	});
	for (int i = 1; i <= n; ++ i) {
		s[i] = s[i - 1] + a[i].first;
	}

	for (int j = 1; j <= n; ++ j) f[0][j] = -oo;
	for (int i = 1; i <= n; ++ i) {
		f[i][0] = f[i - 1][0] + a[i].first;
		for (int j = 1; j <= n; ++ j) {
			f[i][j] = f[i - 1][j] + a[i].first;
			if (f[i - 1][j - 1] + s[n] - s[i] + a[i].first + a[i].second >= d)
				f[i][j] = max(f[i][j], f[i - 1][j - 1]);
		}
	}
	for (int j = n; j >= 0; -- j) {
		if (f[n][j] >= 0) {
			printf("%d\n", j);
			return;
		}
	} 
}

int main() {
	input();
	solve();
}