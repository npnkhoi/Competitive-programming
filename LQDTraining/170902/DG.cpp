#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
struct point{
    double x, y;
    bool operator < (const point & a) {
        return x < a.x || (x == a.x && y < a.y);
    }
    bool operator == (const point & a) {
        return x == a.x && y == a.y;
    }
};
long long ccw(point &a, point &b, point &c) {
    return (b.x - a.x)*(c.y - b.y) - (c.x - b.x)*(b.y - a.y);
}
void convexHull(vector<point> & p, vector<point> & h) {
    int k = 0, n = p.size();
    h.resize(2*n);
    sort(p.begin(), p.end());
    REP(i, n) {
        while (k >= 2 && ccw(h[k-2], h[k-1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }
    int t = k;
    FOD(i, n-2, 0) {
        while (k > t && ccw(h[k-2], h[k-1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }
    h.resize(k);
}
bool inPolygon(point &p, vector<point> &hull) {
    if (p == hull[0]) return 0;

    int l = 2, r = hull.size() - 2;
    while (l < r) {
        int mi = (l+r)/2;
        if (ccw(hull[0], p, hull[mi]) >= 0) r = mi;
        else l = mi + 1;
    }
    if (p == hull[l]) return 0;
    if (ccw(hull[0], p, hull[l]) < 0) return 0;

    int t = l;
    l = 1, r = t-1;
    while (l < r) {
        int mi = (l+r)/2;
        if (ccw(hull[t], p, hull[mi]) >= 0) r = mi;
        else l = mi + 1;
    }
    if (p == hull[l]) return 0;
    //printf("==> %lld %lld, %lld %lld\n", hull[t].x, hull[t].y, hull[l].x, hull[l].y);
    if (ccw(hull[t], p, hull[l]) < 0 || ccw(hull[l], p, hull[0]) < 0) return 0;
    if (ccw(hull[0], p, hull[t]) == 0 && t == hull.size() - 2) return 0;
    if (ccw(hull[t], p, hull[l]) == 0 && l == t-1) return 0;
    if (ccw(hull[l], p, hull[0]) == 0 && l == 1) return 0;
    return 1;
}
int tc, n, m;
vector<point> a, b;
bool ans;
point t;

int main() {
    //cout << EPS << endl;
    freopen("DG.inp", "r", stdin);
    freopen("DG.out", "w", stdout);
    scanf("%d", &tc);
    REP(khoi, tc) {
        a.clear();
        scanf("%d", &n);
        REP(i, n) {
            scanf("%lf %lf", &t.x, &t.y);
            a.push_back(t);
        }
        convexHull(a, b);
        scanf("%d", &m);
        //cout << n << m << endl;
        ans = 1;
        REP(i, m) {
            scanf("%lf %lf", &t.x, &t.y);
            if (!inPolygon(t, b)) ans = 0;
        }
        if (ans) printf("YES\n"); else printf("NO\n");
    }
}
