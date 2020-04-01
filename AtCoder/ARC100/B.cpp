#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const long long oo = 1e18;
int n, a[N];
long long s[N], part[2][2][2];
long long sum(int l, int r) {
	return s[r] - s[l - 1];
}
void calc(int l, int r, int id) {
	int lo = l, hi = r, mid, bs = lo;
	long long needVal = sum(l, r) / 2;
	while (lo <= hi) {
		//cerr << lo << ' ' << hi << '\n';
		mid = (lo + hi) / 2;
		if (sum(l, mid) <= needVal) {
			bs = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	part[id][0][0] = sum(l, bs);
	part[id][0][1] = sum(bs + 1, r);
	if (bs + 1 == r) bs --;
	part[id][1][0] = sum(l, bs + 1);
	part[id][1][1] = sum(bs + 2, r);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	long long res = (long long) 1e18;
	// cerr << res << "\n";
	for (int i = 2; i <= n - 2; ++ i) {
		calc(1, i, 0);
		calc(i + 1, n, 1);
		//cerr << "done\n";
		for (int x = 0; x <= 1; x ++) {
			for (int y = 0 ; y <= 1; y ++) {
				long long Min = oo, Max = - oo;
				Min = min(min(part[0][x][0], part[0][x][1]), min(part[1][y][0], part[1][y][1]));
				Max = max(max(part[0][x][0], part[0][x][1]), max(part[1][y][0], part[1][y][1]));
				res = min(res, Max - Min);
				//cerr << Min << ' ' << Max << "\n";
			}
		}
	}
	printf("%lld", res);
}
// long long maxMinPart(int l, int r, int parts) {
// 	if (parts == 1) return s[r] - s[l-1];
// 	else {
// 		res = - oo;
// 		for (int k = l; k < r; ++ k) {
// 			for (int partsLeft = 1; partsLeft < parts; ++ partsLeft) {
// 				res = max(res, min(maxMinPart(l, k, partsLeft), maxMinPart(k + 1, r, parts - partsLeft)));
// 			}
// 		}
// 	}
// }
// int maxMinPart(int l, int r) {
// 	int lo = r, hi = r, mid, bs = lo;
// 	long long needVal = (s[r] - s[l - 1] + 1) / 2;
// 	while (lo <= hi) {
// 		mid = (lo + hi) / 2;
// 		if (s[mid] - s[lo - 1] <= needVal) {
// 			bs = mid;
// 			lo = mid + 1;
// 		} else hi = mid - 1;
// 	}
// 	return min(s[bs] - s[lo - 1], s[hi] - s[bs]);
// }
