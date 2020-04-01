#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "LINEGAME"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

struct Point{
    ll x, y;
    operator < (const Point a) {
        if (y != a.y) return x < a.y;
        else return x < a.x;
    }
    Point(): x(0), y(0) {}
    Point(int _x, int _y): x(_x), y(_y) {}
};
const int N = 1e5 + 5;
int n, percent, tc;
Point p[N];

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d", &tc);
    while  (tc --) {
        scanf("%d%d", &n, &percent);
        if (n <= 2) {
            printf("possible");
            continue;
        }
        FOR(i, 1, n) scanf("%lld%lld", &p[i].x, &p[i].y);
        int res = 0;
        FOR(i, 1, n-1) FOR(j, i+1, n) {
            int tmp = 2;
            FOR(k, 1, n) if (k != i && k != j && ccw(p[i], p[j], p[k]) == 0) tmp ++;
            res = max(res, tmp);
            //cerr << i << " " << j << " " << tmp << "\n";
        }
        cerr << n << " " << res << "\n";
        if (res * 100 >= percent * n) printf("possible\n");
        else printf("impossible\n");
    }
}
