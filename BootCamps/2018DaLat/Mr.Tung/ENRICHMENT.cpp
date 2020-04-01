using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp(".inp");
//ofstream out(".out");
vector<vi> a;
ll sum(int x, int y, int u, int v) {
    ll res = a[u][v];
    if (x > 0) res -= a[x-1][v];
    if (y > 0) res -= a[u][y-1];
    if (x > 0 && y > 0) res += a[x-1][y-1];
    return res;
}
int main() {
    freopen("ENRICHMENT.inp", "r", stdin);
    freopen("ENRICHMENT.out", "w", stdout);
    int m, n;
    scanf("%d%d", &m, &n);
    a.resize(m);
    REP(i, m) a[i].resize(n);

    ll res = (ll) 1e15;
    REP(i, m) REP(j, n) {
        scanf("%lld", &a[i][j]);
        if (i > 0) a[i][j] += a[i-1][j];
        if (j > 0) a[i][j] += a[i][j-1];
        if (i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
        if (i >= 2 && j >= 2) res = min(res, sum(i-2, j-2, i, j));
    }
    printf("%lld", res);

    return 0;
}
/** Happy Coding :D */
