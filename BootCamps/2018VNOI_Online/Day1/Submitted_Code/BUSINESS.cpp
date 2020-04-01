#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)
#define task "business"
typedef long long ll;
typedef pair<int, int> ii;

const int N = 3e5 + 5;
const int LOG = 20;
int n, k;
vector<int> adj[N];
int pos[N], dep[N], anc[N][LOG+5], f[N];
bool mark[N], tea[N];
int res;

void dfs(int u) {
    mark[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!mark[v]) {
            dep[v] = dep[u] + 1;
            anc[v][0] = u;
            dfs(v);
        }
    }
}
void initLCA() {
    for (int i = 1; (1 << i) <= n; i++)
    FOR(u, 1, n) if ((1 << i) <= dep[u])
        anc[u][i] = anc[anc[u][i-1]][i-1];
}
int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int tmp  = dep[v] - dep[u];
    FOR(i, 0, LOG) if ((tmp & (1 << i)) > 0) v = anc[v][i];
    if (u == v) return u;
    FORD(i, LOG, 0) if ((1 << i) <= dep[u] && anc[u][i] != anc[v][i]) {
        u = anc[u][i];
        v = anc[v][i];
    }
    return anc[u][0];
}
int dist(int u, int v) {
    return dep[u] + dep[v] - 2*dep[LCA(u, v)];
}

void sub0() {
    int tmp = 0, save = 1;
    FOR(u, 2, n) if (dist(1, u) > tmp) {
        tmp = dist(1, u);
        save = u;
    }
    tmp = 0;
    FOR(i, 1, n) tmp = max(tmp, dist(save, i));
    printf("%d", (tmp+1)/2);
}
int main() {
    //cerr << "here\n";
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i, 1, k) {
        int u;
        scanf("%d", &u);
        tea[u] = 1;
        pos[i] = u;
    }
    REP(i, n-1) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    initLCA();
    //---------------------------
    if (k == 0) {
        sub0();
        exit(0);
    }
    // ----------------------------------
    FOR(u, 1, n) if (!tea[u]) {
        f[u] = n;
        FOR(i, 1, k) f[u] = min(f[u], dist(u, pos[k]));
    }

    res = n;
    FOR(u, 1, n) if (!tea[u]) { /// dat quan moi o day
        int tmp = 0;
        FOR(v, 1, n) if (!tea[v] && v != u)
            tmp = max(tmp, min(f[u], dist(u, v)));
        //printf("%d %d\n", u, tmp);
        res = min(res, tmp);
    }
    printf("%d", res);
    return 0;
}
