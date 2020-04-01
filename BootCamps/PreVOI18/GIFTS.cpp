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
#define task "gifts"
const int N = 2e6 + 5;
int n, k;
ll a[N], l[N], r[N];
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        a[i] += a[i-1];
    }
    FOR(i, k, n)
        l[i] = max(a[i] - a[i - k], l[i-1]);
    FORD(i, n - k + 1, 1)
        r[i] = max(a[i + k - 1] - a[i-1], r[i+1]);
    ll res = (ll)1e18 + 7;
    FOR(i, 1, n - k + 1) res = min(res, max(l[i-1], r[i + k]));
    printf("%lld", res);
    return 0;
}
/** Happy Coding :D */
