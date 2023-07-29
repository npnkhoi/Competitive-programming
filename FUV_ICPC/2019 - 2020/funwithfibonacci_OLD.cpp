#include <bits/stdc++.h>
using namespace std;

const int P = 1e6 + 5;

long long n, k;
int tc, p, f[P], id[P], num[P];

int calc_period(int p) {
	// int a = 0, b = 1, ret = 0;
	// while (1) {
	// 	tmp = a;
	// 	a = b;
	// 	b = (tmp + b) % p;
	// 	ret ++;
	// 	if (a == 0 && b == 1) return ret;
	// }
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; ; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % p;
		if (f[i - 1] == 0 && f[i] == 1) {
			return i - 1;
		}
	}
}

int solve(long long k, long long n, int p) {
	int period = calc_period(p);
	cerr << period << '\n';
	int x = f[n % period];
	// cerr << x << '\n';
	
	memset(id, -1, sizeof id);
	int cnt = 0;

	id[x] = cnt;
	num[cnt] = x;

	while (++cnt) {
		if (cnt == k) {
			return x;
		}

		x = f[x];
		if (id[x] == -1) {
			id[x] = cnt;
			num[cnt] = x;
		} else {
			int chu_ki = cnt - id[x];
			return num[(k - id[x]) % chu_ki + id[x]];
		}
	}	
}

int main() {
	freopen("test.inp", "r", stdin);
	cin >> tc;
	while (tc --) {
		cin >> n >> k >> p;
		cout << solve(k, n, p) << '\n';
	}
}