#include <bits/stdc++.h>
using namespace std;

int tc, a[105], n, u, v;

int main() {
	cin >> tc;
	while (tc --) {
		cin >> n >> u >> v;
		bool diff = false, hole = false;
		for (int i = 1; i <= n; ++ i) {
			cin >> a[i];
			if (a[i] != a[1]) {
				diff = true;
			}
			if (i >= 2 && abs(a[i] - a[i - 1]) >= 2) {
				hole = true;
			}
		}
		if (hole) {
			cout << "0\n";
		} else if (!diff) {
			cout << min(u + v, v + v) << '\n';
		} else {
			cout << min(u, v) << '\n';
		}
	}	
}