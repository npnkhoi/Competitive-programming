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
void dfs(int u) {
    mark[u] = 1;
    REP(j, adj[u].size()) {
        ii v = adj[u][j];
        if (mark[v.fi] == 0) {
            anc[v.fi][0] = u;
            mxEdge[v.fi][0] = v.se;
            dep[v.fi] = dep[u] + 1;
            dfs(v.fi);
        }
    }
}
void init() {
    for (int i = 1; (1 << i) <= n; i++)
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, m) scanf("%d%d%d", &e[i].se.fi, &e[i].se.se, &e[i].fi);
    sort(e, e+m);
    REP(i, m) {
        int u = e[i].se.fi, v = e[i].se.se;
        if (root(u) != root(v)) {
            unite(u, v);
            int c = e[i].fi;
            tmp += c;
            adj[u].pb(mp(v, c));
            adj[v].pb(mp(u, c));
        }
    }
    dfs(1);
    init();
    return 0;
}
/** Happy Coding :D */
