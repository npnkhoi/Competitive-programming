#include <bits/stdc++.h>
using namespace std;

int tc, n;
int a[200005];

int main() {
	cin >> tc;
	while (tc --) {
		cin >> n;
		int res = -1;
		for (int i = 0; i < n; ++ i) {
			cin >> a[i];
			if (i > 0 && abs(a[i] - a[i-1]) > 1) res = i;
		}
		if (res == -1) cout << "NO\n";
		else {
			cout << "YES\n" << res << ' ' << res+1 << '\n';
		}
	}
}