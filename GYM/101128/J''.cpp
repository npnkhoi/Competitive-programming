#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
typedef long long ll;
struct point{
    ll x, y;
    bool operator < (const point & a) {
        return x < a.x || (x == a.x && y < a.y);
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
    int l = 2, r = hull.size() - 2;
    while (l < r) {
        int mi = (l+r)/2;
        if (ccw(hull[0], p, hull[mi]) >= 0) r = mi;
        else l = mi + 1;
    }
    if (ccw(hull[0], p, hull[l]) < 0) return 0;

    int t = l;
    l = 1, r = t-1;
    while (l < r) {
        int mi = (l+r)/2;
        if (ccw(hull[t], p, hull[mi]) >= 0) r = mi;
        else l = mi + 1;
    }
    //printf("==> %lld %lld, %lld %lld\n", hull[t].x, hull[t].y, hull[l].x, hull[l].y);
    return ccw(hull[t], p, hull[l]) >= 0 && ccw(hull[l], p, hull[0]) >= 0;
}
int main() {
    int m, n, res = 0;
    vector<point> v, hull;
    scanf("%d", &n);
    while (n--) {
        point tmp;
        scanf("%lld %lld", &tmp.x, &tmp.y);
        v.push_back(tmp);
    }
    convexHull(v, hull);
    //REP(i, hull.size()) printf("(%lld;%lld)\n", hull[i].x, hull[i].y);
    scanf("%d", &m);
    while (m--) {
        point tmp;
        scanf("%lld %lld", &tmp.x, &tmp.y);
        res += inPolygon(tmp, hull);
        //printf("%d\n", res);
    }
    printf("%d", res);
}
