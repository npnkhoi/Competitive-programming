#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

struct Point{
    double X, Y;
    //Point(int _x, int _y) : X(_x), Y(_y) {}
};
const double PI = acos(-1);
vector<Point> v, t;
int tc, n;
double s1;

double ccw(Point a, Point b, Point c) {
    return (b.X - a.X) * (c.Y - b.Y) - (b.Y - a.Y) * (c.X - b.X);
}
Point shPoint(Point a, double dist, double angle) {
    Point b;
    b.X = a.X + dist * cos(angle * PI / 180.0);
    b.Y = a.Y + dist * sin(angle * PI / 180.0);
    return b;
}
void convexHull(vector<Point> &v, vector<Point> &hull) {
    //REP(i, v.size()) cerr << v[i].X << " " << v[i].Y << "\n";
    sort(v.begin(), v.end(), [](Point a, Point b){
        return a.X < b.X;
    });
    hull.clear();
    REP(i, v.size()) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), v[i]) <= 0)
            hull.pop_back();
        hull.push_back(v[i]);
    }

    int flag = hull.size();
    FORD(i, v.size() - 2, 0) {
        while (hull.size() > flag && ccw(hull[hull.size() - 2], hull.back(), v[i]) <= 0)
            hull.pop_back();
        hull.push_back(v[i]);
    }
}

double area(vector<Point> &v) {
    double s = 0;
    int n = v.size();
    REP(i, n) {
        int j = i + 1;
        if (j >= n) j = 0;
        s += v[i].X * v[j].Y - v[i].Y * v[j].X;
    }
    return fabs(s/2);
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        v.clear(); t.clear();
        s1 = 0;
        scanf("%d", &n);
        REP(i, n) {
            Point mid;
            double w, h, ang;
            scanf("%lf%lf%lf%lf%lf", &mid.X, &mid.Y, &w, &h, &ang);
            s1 += w * h;

            ang = 90 - ang;
            double shDist = sqrt(w*w/4 + h*h/4);
            double shAngle = atan(w/h) * 180.0 / PI;
            //cerr << shDist << " " << shAngle << "\n";
            v.push_back(shPoint(mid, shDist, ang + shAngle));
            v.push_back(shPoint(mid, shDist, ang + 180.0 - shAngle));
            v.push_back(shPoint(mid, shDist, ang - shAngle));
            v.push_back(shPoint(mid, shDist, ang - 180.0 + shAngle));
        }
        convexHull(v, t);
        //REP(i, t.size()) cerr << t[i].X << " " << t[i].Y << "\n";
        cerr << s1 << " " << area(t) << "\n";
        printf("%.1f %\n", 100 * s1 / area(t));
    }
}
