#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, a[N], cnt[2];

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	while (q --) {
		int x, y;
		cin >> x >> y;
		if (x == 1) {
			cnt[a[y]] --;
			a[y] = 1 - a[y];
			cnt[a[y]] ++;
		} else {
			if (y <= cnt[1]) {
				cout << "1\n";
			} else {
				cout << "0\n";
			}
		}
	}
}