#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

#define taskName ""
const int N = 52;
const ll md = 1e9 + 7;
ll dp[N][N][N][N], m, n, k;
ll Exp(ll a, ll x) {
    if (x == 0) return 1;
    else {
        ll s = Exp(a, x >> 1);
        s = s * s % md;
        if (x&1) s = s * a % md;
        return s;
    }
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%lld%lld%lld", &m, &n, &k);
    dp[0][0][0][0] = 1;
    ll res = 0;
    FOR(a, 0, n)
    FOR(b, 0, n-a)
    FOR(c, 0, n-a-b)
    FOR(d, 0, n-a-b-c) if (a||b||c||d) {
        if (a > 0) dp[a][b][c][d] = (dp[a][b][c][d] + dp[a-1][b][c][d]) % md;
        if (b > 0) dp[a][b][c][d] = (dp[a][b][c][d] + dp[a][b-1][c][d]) % md;
        if (c > 0) dp[a][b][c][d] = (dp[a][b][c][d] + dp[a][b][c-1][d]) % md;
        if (d > 0) dp[a][b][c][d] = (dp[a][b][c][d] + dp[a][b][c][d-1]) % md;
        if (a+b+c+d == n) {
            int cnt = (a > 0) + (b > 0) + (c > 0) + (d > 0);
            if (cnt >= k) res = (res + dp[a][b][c][d]) % md;
        }
    }
    printf("%lld", Exp(res, m));

    return 0;
}
/** Happy Coding :D */
