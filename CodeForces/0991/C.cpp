#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task "BULMART"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

ll n;
bool ok(ll k) {
    ll m = n, s = 0;

    while (m > 0) {
        if (m <= k) s += m, m = 0;
        else s += k, m -= k;
        m -= m / 10;
    }
    return 2 * s >= n;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n;
    ll l = 1, r = n, res = n;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (ok(mid)) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << res;
}
