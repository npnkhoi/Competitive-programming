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
    operator < (Pack const a) {
        return dist < a.dist;
    }
    Pack(): p1(0), p2(0), dist(oo) {}
    Pack(int _p1, int _p2, ll _dist): p1(_p1), p2(_p2), dist(_dist) {}
};
ll dist(Point a, Point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
Point p[N], q[N];
int n;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        p[i] = Point(x, y, i);
    }
    //cerr << "-----\n";
    Pack res(1, 1, oo);
    FOR(i, 0, n-2) FOR(j, i+1, n-1)
        if (dist(p[i], p[j]) < res.dist) {
            //cerr << i << " " << j << " " << p[i].id << " " << p[j].id << "\n";
            res.p1 = p[i].id;
            res.p2 = p[j].id;
            res.dist = dist(p[i], p[j]);
        }

    if (res.p1 > res.p2) swap(res.p1, res.p2);
    printf("%d %d %.6f", res.p1, res.p2, sqrt(res.dist));
}
