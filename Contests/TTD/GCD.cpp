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
void init() {
    ll tmp = k;
    for (ll i = 2; i*i <= tmp; ++i) if (tmp%i == 0) {
        fact.push_back(i);
        do tmp /= i;
        while (tmp % i == 0);
    }
    if (tmp > 1) fact.push_back(tmp);
    //REP(j, fact.size()) cerr << fact[j] << " ";
    //cerr << endl;
}
ll ans(ll k, ll n) {
    //cerr << k << " " << n << "\n";
    if (k == 1) return n;
    if (n == 0) return 0;

    ll x = __gcd(k, n);
    k /= x; n /= x;

    ll tmp = 0;
    REP(j, fact.size()) if (k % fact[j] == 0)
        tmp = max(tmp, n-1 - (n-1) % fact[j]);
    return n - tmp + ans(k, tmp);
}
int main() {
    freopen("GCD.inp", "r", stdin);
    freopen("GCD.out", "w", stdout);
    cin >> k >> n;
    init();
    cout << ans(k, n);

    return 0;
}
/** Happy Coding :D */
