#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define task "ARMY"

const int N = 22;
const double EPS = 1e-9;

struct Point{
	double x, y;
	bool operator < (Point oth) {
		if (x != oth.x) return x < oth.x;
		else return y < oth.y;
	}
	bool operator == (Point oth) {
		return abs(x - oth.x) < EPS && abs(y - oth.y) < EPS;
	}
	bool operator != (Point oth) {
		return abs(x - oth.x) >= EPS || abs(y - oth.y) >= EPS;
	}
	Point(): x(0), y(0) {}
	Point(double _x, double _y): x(_x), y(_y) {}
};
struct Line{
	double a, b, c;
	Line(): a(0), b(0), c(0) {}
	Line(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}
	bool operator == (Line oth) {
		return abs(a - oth.a) < EPS && abs (b - oth.b) < EPS && abs (c - oth.c) < EPS;
	}
};
typedef pair<Point, Point> Segment;

int n, del[N], res;
Segment seg[N];
Line line[N];

Line segmentToLine(Segment a) {
	if (a.fi.x == a.se.x) {
		return Line(1, 0, -a.fi.x);
	} else if (a.fi.y == a.se.y) {
		return Line(0, 1, -a.fi.y);
	} else if (a.fi.x == 0 && a.fi.y == 0) {
		return Line(1, - (double) a.se.x / a.se.y, 0);
	} else if (a.fi.x * a.se.y != a.se.x * a.fi.y) {
		return Line(
			(double) (a.fi.y - a.se.y) / (a.fi.x * a.se.y - a.se.x * a.fi.y),
			(double) (a.fi.x - a.se.x) / (a.fi.y * a.se.x - a.se.y * a.fi.x),
			1);
	} else {
		return Line(1, - (double) a.fi.x / a.fi.y, 0);
	}
}

Point intersection(Line u, Line v) {
	double D = - u.a * v.b + v.a * u.b;
	double Dy = u.a * v.c - v.a * u.c;
	double Dx = u.c * v.b - v.c * u.b;
	return Point(Dx / D, Dy / D);
}
long long ccw(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

bool intersect(Segment a, Segment b) {
	return ccw(a.fi, a.se, b.fi) * ccw(a.fi, a.se, b.se) <= 0 && ccw(b.fi, b.se, a.fi) * ccw(b.fi, b.se, a.se) <= 0;
}

int main() {
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%lf%lf%lf%lf", &seg[i].fi.x, &seg[i].fi.y, &seg[i].se.x, &seg[i].se.y);
		if (seg[i].se < seg[i].fi) {
			swap(seg[i].fi, seg[i].se);
		}
		// cerr << seg[i].fi.x << " " << seg[i].fi.y << " " << seg[i].se.x << " " << seg[i].se.y << "\n";
		line[i] = segmentToLine(seg[i]);
		// cerr << "line " << i << " " << line[i].a << " " << line[i].b << " " << line[i].c << "\n";
	}
	int t = n;
	while (t --) {
		for (int i = 1; i < n; ++ i) if (!del[i]) {
			for (int j = i + 1; j <= n; ++ j) if (!del[j]) {
				if (line[i] == line[j] && (!(seg[i].se < seg[j].fi) && !(seg[j].se < seg[i].fi)) ) {
					del[j] = 1;
					// cerr << "del " << j << " keep " << i << "\n";
					if (seg[j].fi < seg[i].fi) {
						seg[i].fi = seg[j].fi;
					}
					if (seg[i].se < seg[j].se) {
						seg[i].se = seg[j].se;
					}
					// printf("new line: %f %f, %f %f\n", seg[i].fi.x, seg[i].fi.y, seg[i].se.x, seg[i].se.y);
				}
			}
		}
	}
	// for (int i = 1; i <= n; ++ i) {
	// 	if (!del[i]) {
	// 		cerr << i << "\n";
	// 		printf("seg %d: %f %f %f %f\n", i, seg[i].fi.x, seg[i].fi.y, seg[i].se.x, seg[i].se.y);
	// 	}
	// }
	for (int i = 1; i <= n; ++ i) if (!del[i]) {
		for (int j = i + 1; j <= n; ++ j) if (!del[j]) {
			for (int k = j + 1; k <= n; ++ k) if (!del[k]) {
				// cerr << i << " " << j << " " << k << "\n";
				if (intersect(seg[i], seg[j]) && intersect(seg[j], seg[k]) && intersect(seg[k], seg[i])) {
					// cerr << "inter " << i << " " << j << " " << k << "\n";
					// cerr << intersection(line[i], line[j]).x << " " << intersection(line[i], line[j]).y << "\n";
					// cerr << intersection(line[j], line[k]).x << " " << intersection(line[j], line[k]).y << '\n';

					if (intersection(line[i], line[j]) != intersection(line[j], line[k])) {
						// cerr << "inter " << i << " " << j << " " << k << "\n";
						// cerr << intersection(line[i], line[j]).x << " " << intersection(line[i], line[j]).y << "\n";
						// cerr << intersection(line[j], line[k]).x << " " << intersection(line[j], line[k]).y << '\n';
						++ res;	
					}
				}
			} 
		}
	}
	printf("%d", res);
}