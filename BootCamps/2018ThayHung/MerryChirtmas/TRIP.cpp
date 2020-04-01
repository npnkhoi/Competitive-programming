#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "trip"
typedef long long ll;
//typedef pair<int, int> ii;

const int N = 1e5 + 5;
const int LOG = 20;

int n;
bool mark[N];
int dep[N], anc[N][LOG + 5], last[N];
long long f[N];
vector<int> adj[N];

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
void preLCA() {
    for (int i = 1; (1 << i) <= n; i++) {
        FOR(u, 1, n) if ((1 << i) <= dep[u]) {
            anc[u][i] = anc[anc[u][i-1]][i-1];
            //printf("%d %d: %d\n", u, i, anc[u][i]);
        }
    }
}
int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int tmp = dep[v] - dep[u];
    FOR(i, 0, LOG) if ((tmp & (1 << i)) > 0) v = anc[v][i];
    if (u == v) return u;
    FORD(i, LOG, 0) if ((1 << i) <= dep[u] && anc[u][i] != anc[v][i])
        u = anc[u][i], v = anc[v][i];
    return anc[u][0];
}
int dist(int u, int v) {
    int t = LCA(u, v);
    //printf("dist %d %d: %d\n", u, v, dep[u] + dep[v] - 2 * dep[t]);
    return dep[u] + dep[v] - 2 * dep[t];
}

void calc(int u) {
    //printf("calc: %d\n", u);
    FOR(v, 1, sqrt(u)) if (u % v == 0) {
        f[v] += dist(last[v], u);
        last[v] = u;
        //printf("%d: %d\n", v, u);
        if (v*v != u) {
            int t = u / v;
            f[t] += dist(last[t], u);
            last[t] = u;
            //printf("%d: %d\n", t, u);
        }

    }
    /*for (int v = u; v <= n; v += u) {
        if (last[v] != 0) f[v] += dist(last[v], u);
        last[v] = u;
    }*/
    mark[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!mark[v]) calc(v);
    }
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%D", &n);
    REP(i, n-1) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    preLCA();
    memset(mark, 0, sizeof mark);
    FOR(i, 1, n) last[i] = 1;
    calc(1);
    FOR(i, 1, n) {
        //cerr << f[i] << " ";
        f[i] += dep[last[i]];
        printf("%lld\n", f[i]);
    }
}
/// Expelliarmus !
