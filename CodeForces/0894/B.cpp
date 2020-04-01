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
const ll md = 1e9 + 7;
ll Exp(ll a, ll x) {
    if (x == 0) return 1;
    else {
        ll res = Exp(a, x/2);
        res = res * res % md;
        if (x%2) res = res * a % md;
        return res;
    }
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    ll m, n, k;
    cin >> m >> n >> k;
    //if (m > n) swap(m, n);

    if (((m%2) ^ (n%2) == 1) && k == -1) cout << 0;
    else cout << Exp(Exp(2, m-1), n-1);

    return 0;
}
/** Happy Coding :D */

