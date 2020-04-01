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
struct Point{ ll x, y;};
const int N = 105;
Point pIn[N], pOut[N];
int tc, m, n;
double res;
ll dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
double triArea(Point a, Point b, Point c) {
    return 0.5 * fabs(
        a.x * b.y - a.y * b.x +
        b.x * c.y - b.y * c.x +
        c.x * a.y - c.y * a.x);
}
double minDist(Point a, Point b, Point c) {
    ll x = dist(c, b);
    ll y = dist(a, c);
    ll z = dist(a, b);
    if (y > x+z) return sqrt(z);
    else if (z > x+y) return sqrt(y);
    return 2 * triArea(a, b, c) / sqrt(x);
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        res = 1e9 + 7;
        scanf("%d", &m);
        FOR(i, 1, m) scanf("%lld%lld", &pIn[i].x, &pIn[i].y);
        scanf("%d", &n);
        FOR(i, 1, n) scanf("%lld%lld", &pOut[i].x, &pOut[i].y);
        FOR(i, 1, m) {
            FOR(j, 1, n) {
                int j2 = (j == n ? 1 : j + 1);
                int i2 = (i == m ? 1 : i + 1);
                res = min(res, minDist(pIn[i], pOut[j], pOut[j2]));
                res = min(res, minDist(pOut[j], pIn[i], pIn[i2]));
            }
        }
        printf("%.10f\n", res/2);
    }
}
