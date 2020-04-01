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
int n, m;
ii save[N];
ll x[N], y[N], d[N];
bool a[N][N], mark[N];

ll dist(int u, int v) {
    if (a[u][v]) return 0;
    else return ((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}
void add(int u) {
    //cerr << "add " << u << "\n";
    mark[u] = 1;
    FOR(v, 1, n) if (!mark[v] && dist(u, v) < d[v]) {
        save[v] = mp(u, v);
        d[v] = dist(u, v);
    }
    //FOR(i, 1, n) cerr << d[i] << " " << save[i].fi << " " << save[i].se << "\n";
    //cerr << "\n";
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%lld%lld", &x[i], &y[i]);
    FOR(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }
    FOR(i, 1, n) d[i] = oo;
    add(1);
    REP(z, n-1) {
        ll tmp = oo;
        int u;
        ii e;
        FOR(i, 1, n) if (!mark[i] && d[i] < tmp) {
            tmp = d[i];
            u = i;
            e = save[i];
        }
        if (!a[e.fi][e.se]) ans.push_back(e);
        add(u);
    }
    printf("%d\n", (int)ans.size());
    REP(i, (int)ans.size()) printf("%d %d\n", ans[i].fi, ans[i].se);
}

