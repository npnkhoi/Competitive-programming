#include <bits/stdc++.h>
using namespace std;

const int N = 205, K = 1005, md = 1e9 + 7;
int n, k, a[N], f[N][K];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		f[i][0] = 1;
		for (int s = 1; s <= k; ++ s) {
			f[i][s] = f[i - 1][s];
			for (int j = 1; j < i; ++ j) if (a[i] - a[j] <= s) {
				f[i][s] = (f[i][s] + f[i - 1][s + a[j] - a[i]]) % md;
			}
			cerr << i << ' ' << s << ' ' << f[i][s] << '\n'; 
		}
	}
	int res = 0;
	for (int s = 0; s <= k; ++ s) {
		res = (res + f[n][s]) % md;
	}
	cout << res;
}
