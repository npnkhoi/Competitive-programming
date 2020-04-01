#include <bits/stdc++.h>
using namespace std;

const int N = 103;

int tc, n, a[N], b[N], c[N];
long long A[N], total_attack, res;

long long sum(int l, int r) {
	long long ret = 0;
	for (int i = l; i <= r; ++ i) {
		ret += A[i];
	}
	return ret;
}

void back_tracking(int i) {
	res = max(res, total_attack);
	if (i == n + 1) return;

	long long scenario_a = A[i] + a[i] + sum(i + 1, n),
	scenario_b = 0 + sum(i + 1, n) + (long long) b[i] * (n - i) * (n - i + 1) / 2,
	scenario_c = 0 + sum(i + 1, n) + (long long) c[i] * (n - i);

	if (scenario_a >= scenario_b && scenario_a >= scenario_c) {
		total_attack += A[i] + a[i];
		back_tracking(i + 1);
		total_attack -= A[i] + a[i];
	} else {
		if (scenario_b > scenario_c) {
			for (int j = i + 1; j <= n; ++ j) {
				A[j] += (long long) b[i] * (j - i);
			}
			back_tracking(i + 1);
			for (int j = i + 1; j <= n; ++ j) {
				A[j] -= (long long) b[i] * (j - i);
			}
		} else {
			for (int j = i + 1; j <= n; ++ j) {
				A[j] += c[i];
			}
			back_tracking(i + 1);
			for (int j = i + 1; j <= n; ++ j) {
				A[j] -= c[i];
			}

			if (scenario_b == scenario_c) {
				for (int j = i + 1; j <= n; ++ j) {
					A[j] += (long long) b[i] * (j - i);
				}
				back_tracking(i + 1);
				for (int j = i + 1; j <= n; ++ j) {
					A[j] -= (long long) b[i] * (j - i);
				}
			}
		}
	}
}

int main() {
	// freopen("test.inp", "r", stdin);
	// freopen("test.out", "w", stdout);
	cin >> tc;
	while (tc --) {
		cin >> n;
		for (int i = 1; i <= n; ++ i) A[i] = 0;
		long long total_attack = 0;

		for (int i = 1; i <= n; ++ i) {
			cin >> a[i] >> b[i] >> c[i];
		}
		total_attack = res = 0;
		back_tracking(1);
		cout << res << '\n';
	}
}