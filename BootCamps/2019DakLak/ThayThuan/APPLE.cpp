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
    ll X, Y;
};
vector<Point> tri;
Point tree;
int n, res;

ll ccw(Point a, Point b, Point c) {
    return (b.X - a.X) * (c.Y - b.Y) - (b.Y - a.Y) * (c.X - b.X);
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

bool inPolygon(Point p, vector<Point> &v) {
    int n = v.size();
    bool pos = 0, neg = 0;
    REP(i, n) {
        int j = i + 1;
        if (j >= n) j = 0;
        ll tmp = ccw(v[i], p, v[j]);
        if (tmp > 0) pos = 1; else if (tmp < 0) neg = 1;
    }
    return !(pos & neg);
}


int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    tri.resize(3);
    REP(i, 3) scanf("%lld%lld", &tri[i].X, &tri[i].Y);
    printf("%.1f\n", area(tri));
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%lld%lld", &tree.X, &tree.Y);
        res += inPolygon(tree, tri);
    }
    printf("%d", res);
}
