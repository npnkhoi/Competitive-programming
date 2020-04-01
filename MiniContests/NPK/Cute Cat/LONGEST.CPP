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
const int N = 1e5 + 5;
const int LOG = 20;
int n, a[N], gcd[N][LOG+2];
vector<ii> v, ans;
int maxLen;

int getGCD(int l, int r) {
    int res = a[l];
    FORD(i, LOG, 0) if (l + (1 << i) - 1 <= r) {
        res = __gcd(res, gcd[l][i]);
        l += (1 << i);
        if (l > r) break;
    }
    return res;
}
int maxLeft(int i) {
    int l = 1, r = i, res = i;
    while (l <= r) {
        int mi = (l+r)/2;
        if (getGCD(mi, i) == a[i]) {
            res = min(res, mi);
            r = mi - 1;
        } else l = mi + 1;
    }
    return res;
}
int maxRight(int i) {
    int l = i, r = n, res = i;
    while (l <= r) {
        int mi = (l+r)/2;
        if (getGCD(i, mi) == a[i]) {
            res = max(res, mi);
            l = mi + 1;
        } else r = mi - 1;
    }
    return res;
}

int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        gcd[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
    FOR(i, 1, n) if (i + (1<<j) - 1 <= n)
        gcd[i][j] = __gcd(gcd[i][j-1], gcd[i + (1<<(j-1))][j-1]);
    else break;
    FOR(i, 1, n) {
        int l = maxLeft(i), r = maxRight(i);
        v.push_back(mp(l, r));
        maxLen = max(maxLen, r-l);
    }
    sort(v.begin(), v.end());
    REP(i, v.size()) if (v[i].se - v[i].fi == maxLen)
    if (i == 0 || v[i] != v[i-1]) ans.push_back(v[i]);
    printf("%d\n", ans.size());
    REP(i, ans.size()) printf("%d %d\n", ans[i].fi, ans[i].se);
    return 0;
}
/** Happy Coding :D */

