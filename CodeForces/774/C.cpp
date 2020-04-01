#include <bits/stdc++.h>
using namespace std;

bool check(int x) {

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> col[i] >> r[i] >> b[i];
	}
	int l = 0, r = oo, mid, bs = r;
	while (l <= r) {
		mid = (l + r) / 2;
		if (ok(mid)) {
			bs = mid;
			r = mid - 1;
		} else l = mid + 1;	
	}
	cout << bs;
}