 #include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], c[N], n, tc;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	while (tc --) {
		bool ok = true;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			c[i] = b[i] - a[i];
			if (c[i] < 0) ok = false;
		}
		if (!ok) {
			cout << "NO\n";
			continue;
		}

		int l = 0;
		for (int i = 0; i < n; ++ i) {
			if (c[i] != 0) {
				l = i;
				break;
			}
		}
		if (c[l] == 0) {
			cout << "YES\n";
			continue;
		}

		int r = l;
		for (int j = l + 1; j < n; ++ j) {
			if (c[j] != c[l]) {
				r = j;
				break;
			}
		}
		if (c[r] == c[l]) {
			cout << "YES\n";
			continue;
		}
		if (c[r] != 0) {
			cout << "NO\n";
			continue;
		}
		for (int i = r + 1; i < n; ++ i) {
			if (c[i] != 0) ok = false;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	
}