using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int N = 1e5 + 10;
const int Q = 1e5 + 10;
const int M = 2*N;
vi adj[N];
int par[N], p[N], sign[N], n, m, q;
int First[N], Last[N], idx;
int a[M], f[M], d[M], IT[4*M], cntP[N], cntT[N];
pair<int, ii> e[N];
vector<pair<ii, ii> > P;
vector<pair<int, ii> > T;
int ans[Q];

void make_directed(int u) {
    Last[u] = First[u] = ++idx;
    FOR(j, 0, adj[u].size() - 1) {
        int v = adj[u][j];
        if (First[v] == 0) {
            par[v] = u;
            make_directed(v);
            Last[u] = Last[v];
        }
    }
}

void findDepth(int u) {
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (deep[v] != -1) continue;
        dep[v] = dep[u] + 1;
        findDepth(v);
    }
}

void findAnc() {
    for (int i = 1; i <= n; i++)
    for (int j = 0; j < adj[i].size(); j++)
        anc[adj[i][j]][0] = i;
    for (int j = 1; j <= 65; j++)
    for (int i = 1; i <= n; i++)
    if ((1<<j) <= dep[i]) anc[i][j] = anc[anc[i][j-1]][j-1];
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    while (dep[u] < dep[v]) {
        int x = int(floor(log(double(dep[v] - dep[u])) / log(2.0)));
        v = anc[v][x];
    }
    if (u == v) return u;
    for (int x = dep[u]; x > -1; x--)
        if (anc[u][x] != anc[v][x])
            u = anc[u][x], v = anc[v][x];
    return anc[u][0];
}

int main() {
    freopen("TREE.inp","r",stdin);
    //freopen("TREE.out","w",stdout);
    scanf("%d %d", &n, &q);
    FOR(i, 1, n-1) {
        int u, v, c;
        scanf("%d %d %d", &e[i].se.fi, &e[i].se.se, &e[i].fi);
        adj[e[i].se.se].push_back(e[i].se.fi);
        adj[e[i].se.fi].push_back(e[i].se.se);
    }
    //====================================================================
    memset(sign, 0, sizeof sign);
    memset(par, -1, sizeof par);
    idx = 0;
    memset(First, 0, sizeof First);
    make_directed(1);

    memset(dep, -1, sizeof dep);
    dep[1] = 0;

    findDepth(1);
    findAnc();


    m = 2*n-1;
    idx = 1;
    dfs(1, 1);
    build(1, 1, m);
    //====================================================================
    scanf("%d", &q);
    FOR(i, 1, q) {
        char cmd;
        int u, v, c;
        scanf(" %c", &cmd);
        if (cmd == 'P')
            scanf("%d %d %d", &u, &v, &c),
            P.push_back(mp(mp(c, i), mp(u, v)));
        else
            scanf("%d %d", &u, &c),
            T.push_back(mp(c, mp(i, u)));
    }

    sort(P.begin(), P.end());
    sort(T.begin(), T.end());
    //=====================================================================
    memset(cntP, 0, sizeof cntP);

    idx = 1;
    FOR(i, 0, P.size()-1) {

        int u = P[i].se.fi, v = P[i].se.se;
        while (idx < n && e[idx].fi <= P[i].fi.fi) {
            int x = e[idx].se.fi;
            int y = e[idx].se.se;
            if (First[x] > First[y]) swap(x, y);

            FOR(i, First[y], Last[y]) cntP[i]++;
            idx ++;
            //FOR(i, 1, n) cout << cntP[i] << " "; cout << endl;
        }
        ans[P[i].fi.se] = cntP[First[u]] + cntP[First[v]] - 2*cntP[First[LCA(u, v)]];
    }

    //======================================================================
    memset(cntT, 0, sizeof cntT);
    idx = 1;
    FOR(i, 0, T.size()-1) {
        int k = T[i].se.se, c = P[i].fi;
        while (idx < n && e[idx].fi <= c) {
            int x = e[idx].se.fi;
            int y = e[idx].se.se;
            if (First[x] > First[y]) swap(x, y);

            FOR(i, First[y], Last[y]) cntT[i]++;
            idx ++;
            //FOR(i, 1, n) cout << cntP[i] << " "; cout << endl;
        }
        ans[P[i].fi.se] = cntP[First[u]] + cntP[First[v]] - 2*cntP[First[LCA(u, v)]];
    }
}
/**/
