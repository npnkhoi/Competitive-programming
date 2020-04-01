#include <bits/stdc++.h>
using namespace std;

#define double long double

const int N = 1005;

struct Point {
	double x, y;
	Point() {}
};

int n, m, d[N], r[N];
Point a[N], b[N];

double dist(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dist2(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double area(Point a, Point b, Point c) {
	return fabs(
		a.x * b.y - a.y * b.x +
		b.x * c.y - b.y * c.x +
		c.x * a.y - c.y * a.x);
}

double distToSeg(Point a, Point b, Point c) {
	if (dist2(a, c) >= dist2(a, b) + dist2(b, c)) return dist(a, b);
	if (dist2(a, b) >= dist2(a, c) + dist2(b, c)) return dist(a, c);
	return area(a, b, c) / dist(b, c);
} 

int main() {
	// freopen("A.inp", "r", stdin);
	// freopen("khoi.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i].x >> a[i].y >> d[i] >> r[i];
	}
	cin >> m;
	for (int i = 1; i <= m; ++ i) {
		cin >> b[i].x >> b[i].y;
	}
	if (m == 1) {
		m = 2;
		b[2].x = b[1].x;
		b[2].y = b[1].y;
	}
	long long res = 0;
	for (int i = 1; i <= n; ++ i) {
		bool flag = 0;
		for (int j = 1; j < m; ++ j) {
			if (distToSeg(a[i], b[j], b[j + 1]) <= r[i]) {
				flag = 1;
				break;
			}
		}
		if (flag) res += d[i];
	}
	cout << res;
}