using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e5 + 10;
const ll oo = 1e15 + 10;
int n;
ll a[N], l[N], r[N], s[N], res;
ll sum(int l, int r) {
    if (l%2) return s[r] - s[l-1];
    else return s[l-1] - s[r];
}
void solve() {
    FOR(i, 1, n) {
        if (i%2) s[i] = s[i-1] + a[i]; else s[i] = s[i-1] - a[i];
        cout << s[i] << endl;
    }
    cout << endl;
    ll teven = 0, todd = 0;
    r[n+1] = oo;
    FOD(i, n, 1) {
        if (i%2) r[i] = min(r[i+1], sum(i, n) - todd);
        else r[i] = min(r[i+1], teven - sum(i, n));
        if (i%2) todd = max(todd, sum(i, n));
        else teven = max(teven, -sum(i, n));
        cout << sum(i, n) << " " << r[i] << " " << todd << " " << teven << " " << res << endl;
    }
    todd = 0;
    teven = oo;
    FOR(i, 1, n-1) {
        l[i] = max(l[i-1], max(sum(1, i) - teven, todd - sum(1, i)));
        res = max(res, abs(l[i] - r[i+1])); //cout << l[i] << " " << r[i+1] << endl;
        if (i % 2 == 0) teven = max(teven, sum(1, i));
        todd = max(todd, sum(1, i));
        cout << sum(1, i) << " " << l[i] << " " << todd << " " << teven << " " << res << endl;
    }
}
int main() {
    freopen("0.in","r",stdin);
    //freopen("","w",stdout);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        FOR(i, 1, n) scanf("%lld", &a[i]);
        res = 0;
        solve();
        FOR(i, 1, n) a[i] = -a[i];
        solve();
        printf("%lld\n", res);
    }
    return 0;
}
/** Happy Coding ^^ */

