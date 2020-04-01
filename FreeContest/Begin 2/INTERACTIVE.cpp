#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#define ld long double
using namespace std;

#define fi first
#define se second

int question(ld x,ld y)
{
	cout << "Q " << setprecision(10) << fixed << x << ' ' << y << endl;
	int res;
	cin >> res;
	return res;
}

void answer(ld x1,ld y1,ld x2,ld y2,ld x3,ld y3)
{
	cout << "A " << setprecision(10) << fixed << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
}

pair<ld, ld> a[7];
int c[7];

int main() 
{
	ld tmp = sqrt(3);
	a[0] = make_pair(0.5, 0);
	a[1] = make_pair(1.5, 0);
	a[2] = make_pair(2, tmp / 2);
	a[3] = make_pair(1.5, tmp);
	a[4] = make_pair(0.5, tmp);
	a[5] = make_pair(0, tmp / 2);
	a[6] = make_pair(1, tmp / 2);
	for (int i = 0; i < 7; ++ i) {
		c[i] = question(a[i].fi, a[i].se);
	}

	for (int i = 0; i < 6; ++ i) {
		int j = (i == 5 ? 0 : i + 1);
		if (c[i] == c[j] && c[j] == c[6]) {
			answer(a[i].fi, a[i].se, a[j].fi, a[j].se, a[6].fi, a[6].se);
			return 0;
		}
	}
	if (c[0] == c[2] && c[2] == c[4]) {
		answer(a[0].fi, a[0].se, a[2].fi, a[2].se, a[4].fi, a[4].se);
		return 0;
	} else {
		answer(a[1].fi, a[1].se, a[3].fi, a[3].se, a[5].fi, a[5].se);
		return 0;
	}
	return 0;
}
