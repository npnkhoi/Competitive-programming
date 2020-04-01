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
        if (y != a.y) return y < a.y;
        else return x < a.x;
    }
    Point(): x(0), y(0) {}
    Point(ll _x, ll _y): x(_x), y(_y) {}
};
const int N = 1e5 + 5;
int n, percent, tc, res;
Point p[N];

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
ll Rand(int l, int r) {
    return l + (
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
        1LL * rand() * (RAND_MAX + 1) +
        1LL * rand()) % (r - l + 1);
}
void sub1() {
    int res = 0;
    FOR(i, 1, n-1) FOR(j, i+1, n) {
        int tmp = 2;
        FOR(k, j+1, n) if (k != i && k != j && ccw(p[i], p[j], p[k]) == 0) tmp ++;
        res = max(res, tmp);
    }
    if (res * 100 >= percent * n) printf("possible\n");
    else printf("impossible\n");
}
void sub2() {
    int res = 2;
    REP(z, 100) {
        int u = Rand(1, n-1);
        int v =  Rand(u+1, n);
        int tmp = 2;
        FOR(t, 1, n) if (t != u && t != v && ccw(p[u], p[v], p[t]) == 0) {
            tmp ++;
            res = max(res, tmp);
        }
        if (res * 100 >= percent * n) {
            printf("possible\n");
            return;
        }
    }
    printf("impossible\n");
}

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    while  (tc --) {
        scanf("%d%d", &n, &percent);
        if (n <= 2) {
            printf("possible\n");
            continue;
        }
        FOR(i, 1, n) scanf("%lld%lld", &p[i].x, &p[i].y);
        if  (n <= 400) sub1();
        else sub2();
    }
}
