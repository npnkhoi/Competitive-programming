#include <bits/stdc++.h>
using namespace std;

const int N = 105;

map<pair<int, pair<long long, long long>>, long long> memo;
int tc, n, a[N], b[N], c[N];

long long dp(int i, long long A, long long D) {
	if (i == n + 1) return 0;
	if (memo.find({i, {A, D}}) != memo.end()) {
		return memo[{i, {A, D}}];
	}

	long long ret = dp(i + 1, A + D, D) + A + D + a[i];
	ret = max(ret, dp(i + 1, A + D, D + b[i]));
	ret = max(ret, dp(i + 1, A + D + c[i], D));

	memo[{i, {A, D}}] = ret;
	return ret;
}

int main() {
	freopen("test.inp", "r", stdin);
	freopen("test.ans", "w", stdout);
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	while (tc --) {
		cin >> n;
		for (int i = 1; i <= n; ++ i) {
			cin >> a[i] >> b[i] >> c[i];
		}
		memo.clear();
		cout << dp(0, 0, 0) << '\n';
	}
}