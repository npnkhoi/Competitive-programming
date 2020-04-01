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
int n, m;

ll ccw(ii &a, ii &b, ii &c) {
    return (ll) (b.fi - a.fi) * (c.se - b.se) - (ll) (b.se - a.se) * (c.fi - b.fi);
}
ll ahihi(ii &a, ii &b) {
    return (ll) a.fi * b.se - (ll) a.se * b.fi;
}
ll area(int a, int b, int c) {
    return abs(ahihi(v[a], v[b]) + ahihi(v[b], v[c]) + ahihi(v[c], v[a]));
}
int main() {
    freopen("TRILAND.inp", "r", stdin);
    freopen("TRILAND.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int m = 0;
    FOR(i, 1, n) scanf("%d%d", &a[i].fi, &a[i].se);
    ///-----------------------------------------
    sort(a+1, a+n+1);
    FOR(i, 1, n) {
        while (m >= 2 && ccw(v[m-1], v[m], a[i]) <= 0) --m;
        v[++m] = a[i];
    }
    int k = m;
    FORD(i, n, 1) {
        while (m > k && ccw(v[m-1], v[m], a[i]) <= 0) --m;
        v[++m] = a[i];
    }
    ll res = 0;
    if (m > 3 && ccw(v[m-1], v[m], v[1]) <= 0) --m;
    ///-----------------------------------------
    FOR(i, 1, m-2) FOR(j, i+2, m) {
        int l, r;

        l = i+1, r = j-1;
        while (l <= r) {
            int mi = (l+r)>>1;
            ll s1 = area(i, j, mi);
            ll s2 = area(i, j, mi+1);
            if (s1 >= s2) {
                res = max(res, s1);
                r = mi - 1;
            } else l = mi + 1;
        }
    }
    printf("%lld.%lld", res/2, res%2*5);

    return 0;
}
/** Happy Coding :D */
