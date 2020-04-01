#include <bits/stdc++.h>
using namespace std;

int tc, n, k1, k2, x;
int side[105];

int main() {
	cin >> tc;
	while (tc --) {
		cin >> n >> k1 >> k2;
		while (k1 --) {
			cin >> x;
			side[x] = 1;
		}
		while (k2 --) {
			cin >> x;
			side[x] = 2;
		}
		cout << (side[n] == 1 ? "YES" : "NO") << '\n';
	}
}