#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, BITS = 60;
long long MOD = 1e9 + 7;

long long a[N];
int cnt[BITS + 4];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc;
	cin >> tc;
	while (tc --) {
		int n;
		cin >> n;
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++ i) {
			cin >> a[i];
			for (int j = 0; j < BITS; ++ j) {
				cnt[j] += a[i] >> j & 1;
			}
		}
		long long res = 0;
		for (int i = 0; i < n; ++ i) {
			long long expo = 1;
			long long sum_left = 0, sum_right = 0;	
			for (int bit = 0; bit < BITS; ++ bit) {
				if (a[i] >> bit & 1) {
					sum_left = (sum_left + cnt[bit] * expo % MOD) % MOD;
				}
				if (a[i] >> bit & 1) {
					sum_right = (sum_right + n * expo % MOD) % MOD;
				} else {
					sum_right = (sum_right + cnt[bit] * expo % MOD) % MOD;
				}
				// cerr << sum_left << ' ' << sum_right << '\n';
				expo = (expo + expo) % MOD;
			}
			res = (res + sum_left * sum_right % MOD) % MOD;
			// cerr << "res = " << res << '\n';
		}
		cout << res << '\n';
	}
}