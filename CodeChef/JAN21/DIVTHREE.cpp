#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc --) {
		int n, k, d, s = 0;
		cin >> n >> k >> d;
		for (int i = 0; i < n; ++ i) {
			int x; cin >> x;
			s += x;
		}
		cout << min(s / k, d) << '\n';
	}
}