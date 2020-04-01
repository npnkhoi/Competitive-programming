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
const ll md = 1e9 + 7;
ll Exp(ll a, ll x) {
    if (x == 1) return a;
    else {
        ll s = Exp(a, x/2);
        s = s*s % md;
        if (x % 2) s = s * a % md;
        return s;
    }
}
int main() {
    freopen("MANG.inp", "r", stdin);
    freopen("MANG.out", "w", stdout);
    ll n;
    cin >> n;
    ll res = 1;
    FOR(i, n+1, 2*n-1) res = (res * i) % md;
    FOR(i, 2, n-1) res = (res * Exp(1LL * i, md-2)) % md;
    res = (2*res + md - n) % md;
    cout << res;
    return 0;
}
/** Happy Coding :D */
