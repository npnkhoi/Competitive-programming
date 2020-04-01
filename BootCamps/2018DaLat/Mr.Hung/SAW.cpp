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
const int P = 1e8 + 2;
const int N = 1e6 + 5;
const int oo = 1e9 + 7;
int k, n, m;
double res;
ii a[N];
ii b[N], v[N];
ll ccw(ii &a, ii &b, ii &c) {
    return (ll)(b.fi - a.fi)*(c.se - b.se) - (ll)(c.fi - b.fi)*(b.se - a.se);
}
void update(ii &p) {
    //printf("update %d %d ", p.fi, p.se);
    while (m >= 2 && ccw(v[m-1], v[m], p) <= 0) --m;
    v[++m] = p;
    //cerr << m << "\n";
}
double area(ii &a, ii &b) {
    double x = b.fi - a.fi;
    double y = a.se - b.se;
    if (x == 0 || y == 0) return 0;
    double X = b.fi + x / y * b.se;
    double Y = a.se + y / x * a.fi;
    return X * Y;
}
int main() {
    freopen("SAW.INP", "r", stdin);
    freopen("SAW.OUT", "w", stdout);
    ii A = mp(0, oo);
    ii B = mp(oo, 0);

    scanf("%d", &k);

    int p = 0;
    REP(z, k) {
        scanf("%d", &n);
        FOR(i, 0, n) {
            int tx, ty;
            scanf("%d%d", &tx, &ty);
            if (tx < 0) tx = -tx;
            a[++p] = mp(tx, ty);
            if (tx == 0) A.se = min(A.se, ty);
            else if (ty == 0) B.fi = min(B.fi, tx);
        }
    }
    //printf("%d %d\n", A.fi, A.se);
    //printf("%d %d\n", B.fi, B.se);

    int q = 0;
    FOR(i, 1, p) if (ccw(A, a[i], B) >= 0) b[++q] = a[i];

    sort(b+1, b+q+1);
    FOR(i, 1, q) {
        while (m >= 2 && ccw(v[m-1], v[m], b[i]) <= 0) --m;
        v[++m] = b[i];
    }
    //FOR(i, 1, m) printf("%d %d\n", v[i].fi, v[i].se);

    FOR(i, 1, m-1) res = max(res, area(v[i], v[i+1]));

    printf("%.6lf", res);
    return 0;
}
/** Happy Coding :D */
