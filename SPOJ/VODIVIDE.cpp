using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef pair<pair<ll, ll>, ll> pack;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 5000 + 5;
const ll oo = 1e16;
pack a[N];
ll f[N][N];
vector<int> ans1, ans2;
int n;
void trace(int i, int j) {
    if (i == 0) return;

    if (f[i][j] == f[i-1][j]) {
        ans1.push_back(a[i].se);
        trace(i-1, j);
    } else {
        ans2.push_back(a[i].se);
        trace(i-1, j-1);
    }
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%lld", &a[i].fi.fi);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i].fi.se);
        a[i].se = i;
    }
    sort(a+1, a+n+1, greater<pack>());
    for (int j = 1; j <= n; j++) f[0][j] = -oo;
    for (int i = 0; i <= n; i++) f[i][0] = 0;

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    if (2*j <= i)
        f[i][j] = max(f[i-1][j], f[i-1][j-1] + a[i].fi.se);
    else f[i][j] = -oo;
    printf("%lld\n", f[n][n/2]);
    trace(n, n/2);
    for (int i = 0; i < n/2; i++) printf("%d %d\n", ans1[i], ans2[i]);
    return 0;
}
/** Happy Coding ^^ */

