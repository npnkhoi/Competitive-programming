#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "DCTOC"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e3 + 5;
const ll oo = 1e18 + 9;
vector<ii> ans;
vector<pair<ll, ii> > e;
int n, m, Rank[N], lab[N];
ll x[N], y[N];
bool a[N][N];

ll dist(int u, int v) {
    if (a[u][v]) return 0;
    else return ((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}
int root(int u) {
    if (lab[u] == -1) return u;
    else return lab[u] = root(lab[u]);
}
void join(int u, int v) {
    u = root(u), v = root(v);
    if (Rank[u] > Rank[v]) lab[v] = u;
    else {
        lab[u] = v;
        Rank[v] += (Rank[u] == Rank[v]);
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%lld%lld", &x[i], &y[i]);
    FOR(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }
    FOR(i, 1, n-1) FOR(j, i+1, n) e.push_back(mp(dist(i, j), mp(i, j)));
    sort(e.begin(), e.end());

    memset(lab, -1, sizeof lab);
    REP(i, e.size()) {
        int u = e[i].se.fi, v = e[i].se.se;
        if (root(u) != root(v)) {
            //cerr << e[i].fi << ' ' << u << ' ' << v << '\n';
            join(u, v);
            if (!a[u][v]) ans.push_back(mp(u, v));
        }
    }
    printf("%d\n", (int)ans.size());
    //REP(i, ans.size()) printf("%d %d\n", ans[i].fi, ans[i].se);
}

