using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e3 + 10;
ii a[N];
int s, res;
bool cmp(ii x, ii y) {
    return max(y.se, x.se - y.fi) > max(x.se, y.se - x.fi);
}
int main() {
    freopen("SOLDIER.inp", "r", stdin);
    freopen("SOLDIER.out", "w", stdout);
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d %d", &a[i].fi, &a[i].se);
    sort(a, a+n, cmp);
    s = 0; res = 0;
    REP(i, n) {
        res = max(res, a[i].se - s);
        s += a[i].fi;
    }
    cout << res + s;

    return 0;
}
/** Happy Coding ^^ */
