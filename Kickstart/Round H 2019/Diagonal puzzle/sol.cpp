#include <bits/stdc++.h>
using namespace std;

bool solve1() {
	for (int i = 2; i <= n - 1; ++i) {
		ford[i+i] = a[i][i];
	}
	for (int y = 3; y <= n; y += 2) {
		a[1][y] ^= ford[y - 1];
		int diff = y - 1;
		for (int i = 2; i <= n; ++ i) {
			int j = diff + i;
			if (j > n) break;
			a[i][j] ^= ford[]
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> tc;
	for (int nhithun = 1; nhithun <= tc; nhithun++) {
		cin >> n;
		char ch;
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				cin >> ch;
				a[i][j] = (ch == '.');
			}
		}
		solve1();
	}
}