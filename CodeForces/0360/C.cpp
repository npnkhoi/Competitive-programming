#include <bits/stdc++.h>
using namespace std;

const int N = 2005, md = 1e9 + 7;

int n, k, f[N][N], sum[N], res;
string s;

int main() {
	cin >> n >> k >> s;
	f[0][0] = sum[0] = 1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j <= k; ++ j) {
			f[i][j] = (long long) sum[j] * (s[i - 1] - 'a') % md;
			for (int pre = max(i - j / (n - i + 1), 0); pre < i; ++ pre) {
				f[i][j] = (f[i][j] + 
					(long long) f[pre][j - (i - pre) * (n - i + 1)] * ('z' - s[i - 1]) % md) % md;
			}
			sum[j] = (sum[j] + f[i][j]) % md;
		}
	}
	for (int i = 0; i <= n; ++ i) res = (res + f[i][k]) % md;
	cout << res;
}