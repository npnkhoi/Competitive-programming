using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 1e3 + 5;
const int L = 1e4 + 5;
const ll oo = 1e16 + 5;
int n, A, B, D;
ii a[N];
int s[N];
ll dp[N][L];
bool cmp(ii a, ii b) {
    return a.se * b.fi > b.se * a.fi;
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d %d %d", &n, &A, &B, &D);
    B -= A; D -= A; A = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &a[i].fi, &a[i].se);
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i].fi;

    for (int i = 1; i <= n; i++)
    for (int l = 0; l <= B - s[i]; l++)
    dp[i][l] = min(
        dp[i-1][l] + 1LL * abs(s[i] + l - D) * a[i].se,
        dp[i-1][l + a[i].fi] + 1LL * abs(a[i].fi + l - D) * a[i].se);
    ll res = oo;
    for (int l = 0; l <= B - s[n]; l++) res = min(res, dp[n][l]);
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding ^^ */


