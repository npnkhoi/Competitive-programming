#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Point{
	int x, y, id;
};

Point a[N];
int n, k, high, flag, peak, start;
double res, res1, res2, edge, tmp, s;

double dist(int i, int j) {
	return sqrt((double) (a[i].x - a[j].x) * (a[i].x - a[j].x) + (double) (a[i].y - a[j].y) * (a[i].y - a[j].y));
} 

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n + 1; ++ i) {
		scanf("%d", &a[i].x);
		a[i].y = 0;
		a[i].id = i;
	}
	scanf("%d", &a[n + 1].y);

	// method 1 -----------------

	sort(a + 1, a + n + 1, [](Point a, Point b) {
		return a.x < b.x;
	});
	for (int i = 1; i <= n + 1; ++ i) {
		if (a[i].id == k) {
			start = i;
		}
	}
	for (int i = 1; i <= n + 1; ++ i) {
		edge = dist(i, (i == n + 1 ? 1 : i + 1));
		s += edge;
	}
	tmp = dist(start, (start == 1 ? n + 1 : start - 1));
	tmp = max(tmp, dist(start, (start == n + 1 ? 1 : start + 1)));
	s -= tmp;

	// method 2 -------------------

	high = a[n + 1].y;
	sort(a + 1, a + n + 2, [](Point a, Point b) {
		if (a.x != b.x) return a.x < b.x;
		else return a.y < b.y;
	});
	flag = 0;
	for (int i = 1; i <= n + 1; ++ i) {
		if (a[i].y == high) {
			peak = i;
		}
		if (a[i].id == k) {
			start = i;
		}
		if (i > 1 || a[i].x == a[i - 1].x) flag = 1;
	}

	if (flag) {
		if (start == peak - 1) {
			// int r = (peak == n + 1 ? n : n + 1);
			// res = dist(1, r) + min(dist(peak, 1), dist(r, peak)); 
		} else if (start < peak) {
			// cerr << "here\n";
			res1 = dist(start, peak) + dist(peak, n + 1) + dist(n + 1, start)
				+ dist(start, 1);
			res2 = dist(start, 1) + dist(1, peak)
				dist(start, peak - 2) + dist(peak - 2, peak) + dist(peak, peak - 1) + dist(peak - 1, n + 1);
			// cerr << res1 << " " << res2 << "\n";
			res = min(res1, res2);
			if (peak < n + 1) {
				res = min(res, 2 * dist(1, start) + 
				dist(start, peak - 1) + dist(peak - 1, peak) + dist(peak, peak + 1) + dist(peak + 1, n + 1));
			}
		} else {
			res1 = dist(start, peak) + dist(peak, 1) + dist(1, start)
				+ dist(start, n + 1);
			res2 = 2 * dist(start, n + 1) + dist(start, peak + 1) + dist(peak + 1, peak) + dist(peak, 1);
			// cerr << r
			res = min(res1, res2);
		}
	} else {
		if (start == peak) {
			// int r = (peak == n + 1 ? n : n + 1);
			// res = dist(1, r) + min(dist(peak, 1), dist(r, peak)); 
		} else if (start < peak) {
			res1 = dist(start, peak) + dist(peak, n + 1) + dist(n + 1, start)
				+ dist(start, 1);
			res2 = 2 * dist(1, start) + dist(start, peak - 1) + dist(peak - 1, peak) + dist(peak, n + 1);
			res = min(res1, res2);
		} else {
			res1 = dist(start, peak) + dist(peak, 1) + dist(1, start)
				+ dist(start, n + 1);
			res2 = 2 * dist(start, n + 1) + dist(start, peak + 1) + dist(peak + 1, peak) + dist(peak, 1);
			res = min(res1, res2);
		}
	}

	res = min(res, s);
	printf("%.18lf", res);
}