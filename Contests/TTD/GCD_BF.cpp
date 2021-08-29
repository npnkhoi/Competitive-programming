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
vector<ll> fact;
ll k, n;
ll ans(ll k, ll n) {
    if (n == 0) return 0;
    else return 1 + ans(k, n - __gcd(k, n));
}
int main() {
    freopen("GCD.inp", "r", stdin);
    freopen("GCD.ans", "w", stdout);
    cin >> k >> n;
    cout << ans(k, n);

    return 0;
}
/** Happy Coding :D */
