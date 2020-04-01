#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n ;i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
const int N = 1e5 + 10;
const int oo = 1e9 + 10;
iii e[N];
vector<ii> adj[N];
int n, m, anc[20][N], edge[20][N], dep[N], root[N], Rank[N], sign[N];
long long res = 0;
int getRoot(int u) {
    return (u == root[u]) ? u : root[u] = getRoot(root[u]);
}
int join(int u, int v) {
    u = getRoot(u), v = getRoot(v);
    if (Rank[u] > Rank[v]) root[v] = u;
    else {
        root[u] = v;
        if (Rank[u] == Rank[v]) Rank[v] ++;
    }
}
void direct(int u) {
    REP(j, adj[u].size()) {
        int v = adj[u][j].fi;
        if (v != anc[0][u]) {
            anc[0][v] = u;
            edge[0][v] = adj[u][j].se;
            dep[v] = dep[u] + 1;
            direct(v);
        }
    }
}
void initAnc() {
    for (int i = 1; (1<<i) <= n; i++)
    for (int u = 1; u <= n; u++) if ((1<<i) <= dep[u]) {
        edge[i][u] = min(edge[i-1][u], edge[i-1][anc[i-1][u]]);
        anc[i][u] = anc[i-1][anc[i-1][u]];
    }
}
int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int t = dep[v] - dep[u];
    while (t)  {
        v = anc[__builtin_ctz(t)][v];
        t -= t&(-t);
    }
    if (u == v) return u;
    for (int i = int(ceil(log2(dep[u]))); i >= 0; i--)
    if ((1 << i) <= dep[u] && anc[i][u] != anc[i][v])
        u = anc[i][u], v = anc[i][v];
    return anc[0][u];
}
int minEdge(int u, int v) {
    int res = oo;
    int t = dep[v] - dep[u];
    while (t) {
        res = min(res, edge[__builtin_ctz(t)][v]);
        v = anc[__builtin_ctz(t)][v];
        t -= t&(-t);
    }
    return res;
}
int main() {
    freopen("upgranet.inp", "r", stdin);
    freopen("upgranet.out", "w", stdout);
    scanf("%d %d", &n, &m);
    //cout << n << m << endl;
    REP(i, m) scanf("%d %d %d", &e[i].se.fi, &e[i].se.se, &e[i].fi);
    sort(e, e+m, greater<iii>());
    REP(i, n+5) root[i] = i;
    REP(i, m) {
        int u = e[i].se.fi, v = e[i].se.se;
        //cout << u << " " << v << endl;
        if (getRoot(u) != getRoot(v)) {
            //cout << i << "\n";
            sign[i] = 1;
            join(u, v);
            adj[u].push_back(mp(v, e[i].fi));
            adj[v].push_back(mp(u, e[i].fi));
        }
        //cout << "ok\n";
    }
    //cout << "1\n";
    direct(1);
    //cout << "2\n";
    initAnc();
    REP(i, m) if (sign[i] == 0) {
        int u = e[i].se.fi, v = e[i].se.se;
        int t = LCA(u, v);
        res += 1LL * (min(minEdge(t, u), minEdge(t, v)) - e[i].fi);
    }
    printf("%lld", res);
}
