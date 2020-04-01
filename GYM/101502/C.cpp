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
const int N = 1e5 + 10;
ii a[N], c[N];
int n, m, k, x, s, tc;
ll res;
int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d %d %d %d", &n, &m, &k, &x, &s);
        a[0].fi = 0; a[0].se = x;
        FOR(i, 1, m) scanf("%d", &a[i].se); /// potion
        FOR(i, 1, m) scanf("%d", &a[i].fi); /// mana
        sort(a, a+m+1);
        FOR(i, 1, m) a[i].se = min(a[i-1].se, a[i].se);

        FOR(i, 1, k) scanf("%d", &c[i].se);
        FOR(i, 1, k) scanf("%d", &c[i].fi);
        //cout << "ok\n";
        res = 1LL * x * n;
        FOR(i, 0, k) if (s >= c[i].fi) {
            s -= c[i].fi;
            int l = 0, r = m;
            while (l < r) {
                int mi = (l+r+1) / 2;
                if (a[mi].fi <= s) l = mi;
                else r = mi-1;
            }
            res = min(res, 1LL * (n - c[i].se) * a[l].se);
            s += c[i].fi;
        }
        printf("%lld\n", res);
    }

    return 0;
}
/** Happy Coding ^^ */
