#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int tc, n, ft[N], pos[N];
pair<int, int> a[N];

void update(int i, int val) {
	for (; i <= n; i += i&-i) ft[i] += val;
}

int get(int i) {
	int res = 0;
	for (; i; i -= i&-i) res += ft[i];
	return res;
}

int val_at(int i) {
	if (i == 0) return 0;
	int l = 1, r = n, ret = r;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (get(mid) >= i) {
			ret = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	// cerr << "val at " << i << ": " << ret << ", " << a[ret].first << '\n';
	return a[ret].first;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("test.inp", "r", stdin);
	// freopen("test.out", "w", stdout);
	cin >> tc;
	for (int i_test = 1; i_test <= tc; ++ i_test) {
		cin >> n;
		for (int i = 1; i <= n; ++ i) {
			cin >> a[i].first;
			a[i].second = i; 
		}
		sort(a+1, a+n+1, greater<pair<int, int>>());
		// for (int i = 1; i <= n; ++ i) cerr << a[i].first << ", " << a[i].second << '\n';
		for (int i = 1; i <= n; ++ i) {
			pos[a[i].second] = i;
		}

		cout << "Case #" << i_test << ": ";
		int ans = 0;
		memset(ft, 0, sizeof ft);
		for (int i = 1; i <= n; ++ i) {
			// cerr << "pos " << pos[i] << ' ' << a[pos[i]].first << '\n';
			update(pos[i], +1);
			// for (int j = 1; j <= i; ++ j) cerr << val_at(j) << ' ';
			// cerr << '\n';

			while (ans < i && val_at(ans+1) >= ans+1) ans ++;
			cout << ans << ' ';
		}
		cout << '\n';
	}
}