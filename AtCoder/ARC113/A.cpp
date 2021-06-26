#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int min_factor[N], k, cnt_factors[N], exp_of_min_factor[N];
long long f[N];

void sieve(int n) {
	for (int i = 1; i <= n; ++ i) {
		min_factor[i] = i;
	}
	for (int i = 2; i <= n; ++ i) {
		if (min_factor[i] == i) {
			for (long long j = 1LL * i * i; j <= n; j += i) {
				if (min_factor[j] == j) {
					min_factor[j] = i;
				}
			}
		}
	}
}

int main() {
	cin >> k;
	sieve(k);
	f[1] = 1;
	cnt_factors[1] = 1;
	for (int i = 2; i <= k; ++ i) {
		if (min_factor[i] != min_factor[i / min_factor[i]]) {
			cnt_factors[i] = cnt_factors[i / min_factor[i]] * 2;
			exp_of_min_factor[i] = 1;
		} else {
			exp_of_min_factor[i] = exp_of_min_factor[i / min_factor[i]] + 1;
			cnt_factors[i] = cnt_factors[i / min_factor[i]] / exp_of_min_factor[i] * (exp_of_min_factor[i] + 1);
		}
		// printf("min factor of %d is %d\n", i, min_factor[i]);
		// printf("number of factors of %d is %d\n", i, cnt_factors[i]);
		f[i] = f[i - 1] + cnt_factors[i];
	}
	long long res = 0;
	for (int i = 1; i <= k; ++ i) {
		res += f[k / i];
		// cerr << f[k / i] << " -- ";
	}
	cout << res;
}