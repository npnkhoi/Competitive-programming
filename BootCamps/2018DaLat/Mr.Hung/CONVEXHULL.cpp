using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 1e5 + 5;
ii a[N], v[N];

ll ccw(ii &a, ii &b, ii &c) {
    return (ll) (b.fi - a.fi) * (c.se - b.se) - (ll) (b.se- a.se) * (c.fi - b.fi);
}
bool cmp(ii &a, ii &b)  {
    if (a.se != b.se) return a.se < b.se;
    else return a.fi < b.fi;
}

int main() {
    freopen("CONVEXHULL.inp", "r", stdin);
    freopen("CONVEXHULL.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int m = 0;
    FOR(i, 1, n) scanf("%d%d", &a[i].fi, &a[i].se);
    sort(a+1, a+n+1, cmp);
    FOR(i, 1, n) {
        while (m >= 2 && ccw(v[m-1], v[m], a[i]) <= 0) --m;
        v[++m] = a[i];
    }
    int k = m;
    FORD(i, n, 1) {
        while (m > k && ccw(v[m-1], v[m], a[i]) <= 0) --m;
        v[++m] = a[i];
    }
    if (m > 3 && ccw(v[m-1], v[m], v[1]) <= 0) --m;

    ll res = 0;
    FOR(i, 1, m) {
        int j;
        if (i < m) j = i+1; else j = 1;
        res += 1LL * v[i].fi * v[j].se - 1LL * v[i].se * v[j].fi;
    }
    res = abs(res);
    printf("%d\n", m);
    printf("%lld.%lld\n", res/2, res%2*5);
    FOR(i, 1, m) printf("%d %d\n", v[i].fi, v[i].se);
    return 0;
}
/** Happy Coding :D */
