#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

double n, p1, v1, p2, v2;

double total_time(double x) {
	return max((x + min(p1, x - p1)) / v1, (n - x + min(n - p2, p2 - x)) / v2);
}

int main() {
	int tc;
	cin >> tc;
	while (tc --) {
		scanf("%lf%lf%lf%lf%lf", &n, &p1, &v1, &p2, &v2);
		if (p1 > p2) {
			swap(p1, p2);
			swap(v1, v2);
		}

		double l = p1, r = p2, res;
		while (r - l > EPS) {
			double mid = (l + r) / 2;
			if (total_time(mid) - total_time(mid - EPS) <= 0) {
				res = mid;
				l = mid + EPS;
			} else {
				r = mid - EPS;
			}
		}
		double ans = min(total_time(res), max(p2 / v2, (n - p1) / v1));
		ans = min(ans, (n + min(p1, n - p1)) / v1);
		ans = min(ans, (n + min(p2, n - p2)) / v2);
		printf("%.10lf\n", ans);
	}
}