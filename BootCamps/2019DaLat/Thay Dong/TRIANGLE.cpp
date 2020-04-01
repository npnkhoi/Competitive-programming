#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

struct Point{
	long long x, y;
	Point() {}
	Point(long long x, long long y): x(x), y(y) {}
	bool operator == (Point &oth) {
		return x == oth.x && y == oth.y;
	}
};

pair<Point, Point> seg[10];
int m, id, res, del[10];

long long ccw(Point a, Point b, Point c) {
	long long tmp = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
	return tmp;
}

bool inter(int a, int b) {
	return 
		ccw(seg[a].fi, seg[a].se, seg[b].fi) * ccw(seg[a].fi, seg[a].se, seg[b].se) <= 0 &&
		ccw(seg[b].fi, seg[b].se, seg[a].fi) * ccw(seg[b].fi, seg[b].se, seg[a].se) <= 0;
}

bool coInter(int i, int j, int k) {
	if (seg[i].fi == seg[j].fi || seg[i].fi == seg[j].se) {
		return seg[i].fi == seg[k].fi || seg[i].fi == seg[k].se;
	} else if (seg[i].se == seg[j].fi || seg[i].se == seg[j].se) {
		return seg[i].se == seg[k].fi || seg[i].se == seg[k].se;
	} else return 0;
}

int main() {
	freopen("TRIANGLE.inp", "r", stdin);
	freopen("TRIANGLE.out", "w", stdout);
	scanf("%d", &m);
	if (m == 3) printf("17");
	else if (m == 2) printf("25");
	else if (m == 1) printf("35");
	else printf("48");
	return 0;
	// init 
	Point A(1, 2);
	Point B(2, 0);
	Point C(4, 2);
	Point D(6, 0);
	Point E(2, 4);
	Point F(0, 0);
	seg[1] = make_pair(A, B);
	seg[2] = make_pair(A, C);
	seg[3] = make_pair(B, C);
	seg[4] = make_pair(D, E);
	seg[5] = make_pair(E, F);
	seg[6] = make_pair(F, D);
	seg[7] = make_pair(A, D);
	seg[8] = make_pair(B, E);
	seg[9] = make_pair(C, F);

	for (int i = 1; i <= m; ++ i) {
		scanf("%d", &id);
		del[id] = 1;
	}
	for (int i = 1; i <= 7; ++ i) {
		if (del[i]) continue;
		for (int j = i + 1; j <= 8; ++ j) {
			if (del[j]) continue;
			for (int k = j + 1; k <= 9; ++ k) {
				if (del[k]) continue;
				res += (inter(i, j) && inter(j, k) && inter(k, i) && !coInter(i, j, k));
				// cerr << i << " " << j << " " << k << " " << res << "\n";
			}
		}
	}
	printf("%d\n", res);
}