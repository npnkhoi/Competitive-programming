#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const double oo = 1e13;

struct Point{
	int x, y, id;
};

Point a[N];
int n, k, high, flag, peak, start;
double res;

double dist(int i, int j) {
	return sqrt((double) (a[i].x - a[j].x) * (a[i].x - a[j].x) + (double) (a[i].y - a[j].y) * (a[i].y - a[j].y));
} 

double minHop(int l, int r, int u, int v) {
	double res = oo;
	for (int i = l + 1; i <= r; ++ i)
		if (i <= u || v < i)
			res = min(res, dist(i - 1, peak) + dist(peak, i) - dist(i - 1, i));
		else if (i == v) {
			res = min(res, dist(u, peak) + dist(peak, v) - dist(u, v));
		}
	return res;
}

int main() {
	// freopen("KING.inp", "r", stdin);
	// freopen("KING.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n + 1; ++ i) {
		scanf("%d", &a[i].x);
		a[i].y = 0;
		a[i].id = i;
	}
	scanf("%d", &a[n + 1].y);

	sort(a + 1, a + n + 1, [](Point a, Point b) {
		return a.x < b.x;
	});
	peak = n + 1;
	for (int i = 1; i <= n; ++ i) {
		if (a[i].id == k) start = i;
	}

	if (k != n + 1) {	
		if (start == 1) {
			res = dist(1, n) + min(minHop(1, n, -1, -1), dist(n, peak));
		} else if (start == n) {
			res = dist(1, n) + min(minHop(1, n, -1, -1), dist(1, peak));
		} else {
			res = oo;
			res = min(res, dist(start, 1) + dist(1, n) + min(minHop(1, n, 1, start + 1), dist(n, peak)));
			res = min(res, dist(start, n) + dist(n, 1) + min(minHop(1, n, start - 1, n), dist(1, peak)));

			res = min(res, dist(start, 1) + minHop(1, start, -1, -1) + dist(1, n));
			res = min(res, dist(start, 1) + dist(1, peak) + dist(peak, start + 1) + dist(start + 1, n));

			res = min(res, dist(start, n) + minHop(start, n, -1, -1) + dist(n, 1));
			res = min(res, dist(start, n) + dist(n, peak) + dist(peak, start - 1) + dist(start - 1, 1));
		}
	} else {
		res = dist(1, n) + min(dist(peak, 1), dist(peak, n));
	}
	printf("%.10f", res);
}