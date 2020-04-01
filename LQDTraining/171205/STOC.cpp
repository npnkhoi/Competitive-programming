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
#define taskName "stoc"

const int N = 205;
int c[N][N], dp[N];
vector<ii> v;
int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    int m, n;
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) {
        scanf("%d", &c[i][j]);
        v.pb(mp(i, c[i][j]));
    }
    dp[0] = 0;

    FOR(i, 1, m) {
        dp[i] = dp[i-1];
        REP(j, v.size()) {
            int fee = v[j].fi;
            int prof = v[j].se;
            if (fee <= i) dp[i] = max(dp[i], dp[i - fee] + prof);
        }
    }
    printf("%d", dp[m]);
    return 0;
}
/** Happy Coding :D */
