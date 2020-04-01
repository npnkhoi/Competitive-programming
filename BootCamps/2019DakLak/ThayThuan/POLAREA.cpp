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

struct Point{ ll X, Y;};
ll ccw(Point a, Point b, Point c) {
    return (b.X - a.X) * (c.Y - b.Y) - (b.Y - a.Y) * (c.X - b.X);
}
ll area(vector<Point> &v) {
    ll s = 0;
    int n = v.size();
    REP(i, n) {
        int j = i + 1;
        if (j >= n) j = 0;
        s += v[i].X * v[j].Y - v[i].Y * v[j].X;
    }
    return s;
}
vector<Point> v;
int n;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        v.resize(n);
        REP(i, n) scanf("%lld%lld", &v[i].X, &v[i].Y);
        /*int p1 = 0, p2 = 0;
        REP(i, n) if (ccw(v[i], v[(i+1) % n], v[(i+2) % n]) >= 0)
            id1[p1++] = i; else id2[p2++] = i;
        if (p1)
        if (pos > neg) printf("CCW "); else printf("CW ");
        printf("%.1f\n", area(v));*/
        ll tmp = area(v);
        if (tmp < 0) printf("CW "); else printf("CCW ");
        printf("%.1f\n", 0.5*abs(tmp));
    }
}
