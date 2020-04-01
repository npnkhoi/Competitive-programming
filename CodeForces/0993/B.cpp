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

const int N = 15;
int match(ii a, ii b) {
    if (a.fi == b.fi && a.se != b.se) return a.fi;
    if (a.fi == b.se && a.se != b.fi) return a.fi;
    if (a.se == b.fi && a.fi != b.se) return a.se;
    if (a.se == b.se && a.fi != b.fi) return a.se;
    return 0;
}
vector<ii> a, b;
int n, m, cnta[N], cntb[N], cnt, save, marka[N][2], markb[N][2];
set<int> data;
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        a.pb(mp(x, y));
    }
    REP(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        b.pb(mp(x, y));
    }
    REP(i, n) REP(j, m) {
        if (a[i].fi == b[j].fi && a[i].se != b[j].se) marka[i][0] = markb[j][0] = 1;
        if (a[i].fi == b[j].se && a[i].se != b[j].fi) marka[i][0] = markb[j][1] = 1;
        if (a[i].se == b[j].fi && a[i].fi != b[j].se) marka[i][1] = markb[j][0] = 1;
        if (a[i].se == b[j].se && a[i].fi != b[j].fi) marka[i][1] = markb[j][1] = 1;
    }
    REP(i, n) REP(j, m)
    if (match(a[i], b[j])) {
        if ((marka[i][0] ^ marka[i][1]) & (markb[j][0] ^ markb[j][1])) {
            data.insert(match(a[i], b[j]));
        } else {
            printf("-1");
            return 0;
        }
    }
    if (data.size() == 1) printf("%d", *data.begin());
    else printf("0");
}

