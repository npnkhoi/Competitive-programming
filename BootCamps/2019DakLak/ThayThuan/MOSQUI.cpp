#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "mosqui"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

struct Point{double X, Y;};

const int N = 37;
const double EPS = 1e-9;
int tc, n;
double r;
Point mos[N];
double dist(Point a, Point b) {
    return (b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y);
}
double ccw(Point a, Point b, Point c) {
    return (b.X - a.X) * (c.Y - b.Y) - (b.Y - a.Y) * (c.X - b.X);
}
double triArea(Point a, Point b, Point c) {
    return 0.5 * fabs(
        a.X * b.Y - a.Y * b.X +
        b.X * c.Y - b.Y * c.X +
        c.X * a.Y - c.Y * a.X);
}
double Cos(Point a, Point b, Point c) {
    double x = dist(b, c);
    double y = dist(c, a);
    double z = dist(a, b);
    return (x - y - z) / (-2 * sqrt(y*z));
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        scanf("%d%lf", &n, &r);
        r /= 2;
        FOR(i, 1, n) scanf("%lf%lf", &mos[i].X, &mos[i].Y);
        int res = 0;
        FOR(i, 1, n-1)
            FOR(j, i+1, n) {
                double d = sqrt(dist(mos[i], mos[j]));
                if (d > 2*r + EPS) continue;
                double cosCircle = sqrt(0.5*(2 - (d*d) / (2*r*r)));
                int cnt1 = 2, cnt2 = 2;
                FOR(k, 1, n) if (k != i && k != j) {
                    double curCos = Cos(mos[k], mos[i], mos[j]);
                    if (curCos <= -cosCircle) cnt2 ++, cnt1 ++;
                    else if (curCos <= cosCircle) {
                         if (ccw(mos[i], mos[k], mos[j]) >= 0) cnt1 ++;
                         else cnt2 ++;
                    }
                }
                res = max(res, max(cnt1, cnt2));
            }
        printf("%d\n", res);
    }
}
