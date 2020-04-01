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
#define FORD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)

const int N = 5e4 + 5;
const ll oo = 1e17 + 9;
const int maxCoor = 1e9 + 7;

int k;
int x[N], y[N];

ll dist(int a[], int n, int k, int x) {
    ll res = 0;
    for (int cur = 1; cur <= n; ++x) {
        FOR(i, 1, k) {
            res += 1LL * abs(a[cur] - x);
            ++ cur;
        }
    }
    return res;
}
ll ans(int m) {
    //printf("ans %d\n", m);
    int l = -maxCoor, r = maxCoor - 1;
    int res = r;
    while (l <= r) {
        int mi = (l+r)/2;
        if (dist(x, k, m, mi) <= dist(x, k, m, mi+1)) {
            res = min(res, mi);
            r = mi - 1;
        } else l = mi + 1;
    }
    ll s = dist(x, k, m, res);
    //cout << s << endl;

    l = -maxCoor, r = maxCoor - 1;
    res = r;
    m = k/m;
    while (l <= r) {
        int mi = (l+r)/2;
        if (dist(y, k, m, mi) <= dist(y, k, m, mi+1)) {
            res = min(res, mi);
            r = mi - 1;
        } else l = mi + 1;
    }
    s += dist(y, k, m, res);
    //cout << s << endl;

    return s;
}
int main() {
    freopen("QUEUE.inp", "r", stdin);
    freopen("QUEUE.out", "w", stdout);
    scanf("%d", &k);
    FOR(i, 1, k) scanf("%d%d", &x[i], &y[i]);
    sort(x+1, x+k+1);
    sort(y+1, y+k+1);
    ll res = oo;
    //cout << "res: " << res << endl;
    FOR(i, 1, sqrt(k)) if (k % i == 0) {
        res = min(res, min(ans(i), ans(k/i)));
        //cout << "res: " << res << endl;
    }
    printf("%lld\n", res);
     return 0;
}
/** Happy Coding ^^ */

