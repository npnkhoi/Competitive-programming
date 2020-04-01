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

ll ans(ll x) {
    return x * (x+1) * (x+5) / 6 - 1;
}
int main() {
    freopen("DIKE.inp", "r", stdin);
    freopen("DIKE.out", "w", stdout);
    ll n;
    scanf("%lld", &n);
    //cout << ans(2) << endl;
    ll l = 0, r = 1817119;
    ll res = 0;
    while (l <= r) {
        //cerr << l << " " << r << endl;
        ll mi = (l+r)/2;
        if (ans(mi) <= n) {
            l = mi + 1;
            res = max(res, mi);
        } else r = mi - 1;
    }
    cout << res;
    return 0;
}
/** Happy Coding ^^ */

