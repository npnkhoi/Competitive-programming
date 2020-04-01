#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5;
int n, aa, b, d[N], id[N];
ii a[N];
long long tmp, s, mx, POW;
bool cmp(int i, int j) {
    return d[i] > d[j];
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d%d", &n, &aa, &b);
    FOR(i, 1, n) {
        scanf("%d%d", &a[i].fi, &a[i].se);
        d[i] = max(a[i].fi - a[i].se, 0);
        s += a[i].se;
    }
    if (b > 0) {
        if (b > n) b = n;
        FOR(i, 1, n) id[i] = i;
        sort(id + 1, id + n + 1, cmp);
        FOR(i, 1, b) tmp += d[id[i]];
        if (aa == 0) mx = tmp;
        else {
            POW = 1;
            FOR(i, 1, aa) POW *= 2;
            FOR(i, 1, b) mx = max(mx, tmp - d[id[i]] + max(a[id[i]].fi * POW - a[id[i]].se, 0LL));
            tmp -= d[id[b]];
            FOR(i, b+1, n) mx = max(mx, max(a[id[i]].fi * POW - a[id[i]].se, 0LL) + tmp);
        }
    }
    printf("%lld", s + mx);
}
