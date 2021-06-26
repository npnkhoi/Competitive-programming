#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

void add(int &a, int b) {
	a = (a + b) % MOD;
}

void solve() {
	int X, Y;
	cin >> X >> Y;
	int res = 0;
	int bino = min((int)log2(X), (int)log2(Y)) + 1;
	for (int i = 1; i <= bino; ++i) {
		add(res, (1 << (i - 1)) * i);
	}
	cerr << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
 
}