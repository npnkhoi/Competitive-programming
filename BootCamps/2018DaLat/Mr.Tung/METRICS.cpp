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
const int N = 1e5 + 5;
int a[N], b[N];
int c[N];
ll s[N];

ll sum(int l, int r) {
    if (l > r) return 0;

    return s[r] - s[l-1];
}
ll ans(int a[], int n, int b[], int m) {
    ll res = 0;
    FOR(i, 1, m) {
        c[i] = b[i];
    }
    sort(c+1, c+m+1);
    s[0] = 0;
    FOR(i, 1, m) s[i] = s[i-1] + 1LL * c[i];

    FOR(i, 1, n) {
        if (a[i] >= c[m]) {
            res += 1LL * i * (m * a[i] - sum(1, m));
        } else if (a[i] <= c[1]) {
            res -= 1LL * i * (m * a[i] - sum(1, m));
        } else {
            int k = lower_bound(c+1, c+m+1, a[i]) - c;
            res += 1LL * i * (sum(k, m) - 1LL * a[i] * (m-k+1));
            res += 1LL * i * (1LL * (k-1) * a[i] - sum(1, k-1));
        }
    }
    //cerr << endl;
    return res;
}
int main() {
    freopen("METRICS.inp", "r", stdin);
    freopen("METRICS.out", "w", stdout);
    int n, m;
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    scanf("%d", &m);
    FOR(i, 1, m) scanf("%d", &b[i]);
    ll res = ans(a, n, b, m) - ans(b, m, a, n);
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding ^^ */

