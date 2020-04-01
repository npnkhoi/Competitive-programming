#include <bits/stdc++.h>
using namespace std;

#define sqr(x) (x) * (x)
#define X first
#define Y second.first
#define Z second.second
typedef pair<long long, pair<long long, long long>> Point;

int tc, r;
Point O, S, T;

long long dist(Point a, Point b) {
	return sqr(a.X - b.X) + sqr(a.Y - b.Y) + sqr(a.Z - b.Z);
}

int main() {
	cin >> tc;
	while (tc --) {
		cin >> O.X >> O.Y >> O.Z >> r;
		cin >> S.X >> S.Y >> S.Z >> T.X >> T.Y >> T.Z;

		long long ST = dist(S, T);
		if (ST == 0) {
			cout << 0 << '\n';
			continue;
		}
		long long OT = dist(O, T);
		long long OS = dist(O, S);

		long long ax = S.X - O.X, ay = S.Y - O.Y, az = S.Z - O.Z;
		long long bx = T.X - O.X, by = T.Y - O.Y, bz = T.Z - O.Z;
		long long x = ay * bz - az * by;
		long long y = az * bx - ax * bz;
		long long z = ax * by - ay * bx;

		long long h = (sqr(x) + sqr(y) + sqr(z)) / ST;

		if (h >= sqr(r)) cout << fixed << setprecision(10) << sqrt(ST) << '\n';
		else {
			if (OT > OS) swap(OT, OS);
			if (OS > OT + ST) {
				cout << fixed << setprecision(10) << sqrt(ST) << '\n';
			} else {
				double SOT = acos((OS + OT - ST) / (2 * sqrt(OS * OT)));

				double O1 = acos(r / sqrt(OS));
				double O2 = acos(r / sqrt(OT));
				double O3 = SOT - O1 - O2;

				cout << fixed << setprecision(10) << sqrt(OS - sqr(r)) + sqrt(OT - sqr(r)) + O3 * r << '\n';
			}
		}
	}
}