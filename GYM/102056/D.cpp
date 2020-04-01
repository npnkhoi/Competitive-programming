#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc, n, m;
	cin >> tc;
	while (tc --) {
		cin >> n >> m;
		int a = 0, b = 0, x;
		while (n --) {
			cin >> x;
			if (x > 0) a ++;
		}
		while (m --) {
			cin >> x;
			if (x > 0) b ++;
		}
		if (a <= b) cout << "Yes\n";
		else cout << "No\n";
	}
}