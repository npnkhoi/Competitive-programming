#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define taskName ""
void convexHull(vector<P> &a, vector<P> &hull) {
    hull.resize(0);
    sort(a.begin(), a.end());
    REP(i, n) {
        while (hull.size() >= 2 &&
        ccw(hull[hull.size() - 2], hull.back(), a[i]) <= 0) hull.pop();
        hull.pb(a[i]);
    }
    int flag = hull.size();
    FORD(i, n-1, 0) {
        while (hull.size() > flag &&
        ccw(hull[hull.size() - 2], hull.back(), a[i]) <= 0) hull.pop();
    }
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d", &n);
    a.resize(n);
    FOR(i, 1, n) scanf("%d%d", &a[i].x, &a[i].y);
    scanf("%d", &m);
    b.resize(m);
    FOR(i, 1, m) scanf("%d%d", &b[i].x, &b[i].y);
    convexHull(b, c);

    return 0;
}
/** Happy Coding :D */
