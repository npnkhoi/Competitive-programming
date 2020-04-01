#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "clopair"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 5e4 + 5;
const ll oo = 1e18 + 7;
struct Point{
    ll x, y;
    int id;
    Point(): x(0), y(0), id(0) {}
    Point(ll _x, ll _y, int _id): x(_x), y(_y), id(_id) {}
};
struct Pack{
    int p1, p2;
    ll dist;
    Pack(): p1(0), p2(0), dist(oo) {}
    Pack(int _p1, int _p2, ll _dist): p1(_p1), p2(_p2), dist(_dist) {}
};
Point p[N], q[N];
ll dist(Point a, Point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
Pack minDist(int l, int r) {
    if (l >= r) return Pack(0, 0, oo);
    //cerr << "minDist " << l << " " << r << "\n";
    int mi = (l+r) / 2;
    Pack res1 = minDist(l, mi);
    Pack res2 = minDist(mi + 1, r);
    Pack res;
    if (res1.dist < res2.dist) res = res1; else res = res2;
    //cerr << "init " << res.p1 << " " << res.p2 << " " << res.dist << "\n";

    int m = 0;
    for (int i = l; i <= r; i++)
    if (abs(p[i].x - p[mi].x) <= res.dist) {
        q[++m] = p[i];
        //cerr << q[m].x << " " << q[m].y << " " << q[m].id << " into hub\n";
    }
    sort(q+1, q+m+1, [](Point a, Point b){
        return a.y < b.y;
    });
    for (int i = 1; i < m; i++)
    for (int j = i+1; j <= min(i+6, m); j++)
        if (dist(q[i], q[j]) <= res.dist) res = Pack(q[i].id, q[j].id, dist(q[i], q[j]));
    //cerr << l << " " << r << " return " << res.p1 << " " << res.p2 << "\n";
    return res;
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        p[i] = Point(x, y, i);
    }
    sort(p, p+n, [](Point a, Point b) {
        return a.x < b.x;
    });
    Pack res = minDist(0, n-1);
    if (res.p1 > res.p2) swap(res.p1, res.p2);
    printf("%d %d %.6f\n", res.p1, res.p2, sqrt(res.dist));
}
