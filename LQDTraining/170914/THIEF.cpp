using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e5 + 5;
int n, l[N], r[N], trash;
long long m, res;
pll a[N];
stack<int> st;
/*long long cost(int l, int r) {
    if (l == r) return a[l].se;
    int k;
    ll tmp = oo;
    FOR(i, l, r) if (a[i].se < tmp) k = i;
    ll ans = cost(l, k) - tmp;
    if (k < r) ans += cost(k+1, r) - tmp;
    return ans;
}*/
int main() {
    freopen("THIEF.inp", "r", stdin);
    freopen("THIEF.out", "w", stdout);
    scanf("%d %lld", &n, &m);
    FOR(i, 1, n) scanf("%lld %lld", &a[i].fi, &a[i].se);
    sort(a+1, a+n+1);
    FOR(i, 1, n) if (a[i].se > a[i-1].se) res += a[i].se - a[i-1].se;
    cout << res;
    return 0;
}
/** Happy Coding ^^ */
