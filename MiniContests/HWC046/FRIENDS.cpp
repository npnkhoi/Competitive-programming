using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int M = 2e5 + 5;
ii a[M];
int n, m;
bool sign[M];
bool cmp(ii a, ii b) {
    if (a.se - a.fi != b.se - b.fi)
        return a.se - a.fi < b.se - b.fi;
    else return a < b;
}
int pos(ii x) {
    int l = 1, r = m, res = m;
    while (l <= r) {
        int mid = (l+r)/2;
        if (!cmp(a[mid], x)) {
            res = min(res, mid);
            r = mid - 1;
        } else l = mid + 1;
    }
    if (a[res] == x) return res;
    else return 0;
}
int main() {
    freopen("FRIENDS.inp", "r", stdin);
    freopen("FRIENDS.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) {
        scanf("%d%d", &a[i].fi, &a[i].se);
        if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
        //b[i] = a[i];
    }
    sort(a+1, a+m+1, cmp);

    int res = 0;
    FOR(i, 1, m) {
        int x = a[i].fi;
        int y = a[i].se;
        //cerr << x << "  " << y << "\n";
        if (y - x == 1) sign[i] = 1;
            else {
                sign[i] = sign[pos(mp(x+1, y))] && sign[pos(mp(x, y-1))];
                //printf("pos: %d %d\n", pos(mp(x+1, y)), pos(mp(x, y-1)));
            }
        if (sign[i]) res = max(res, y-x+1);
    }
    printf("%d", res);
    return 0;
}
/** Happy Coding ^^ */

