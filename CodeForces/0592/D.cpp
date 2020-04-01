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
vector<int> adj[N], path;
bool att[N], attDown[N], mark[N];
int anc[N][25], dep[N];
int m, n, root;
long long res;

void precalc(int u) {
    //cerr << "precalc " << u << "\n";
    attDown[u] = att[u];
    if (att[u] && !mark[u]) {
        path.pb(u);
        mark[u] = 1;
    }
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (v != anc[u][0]) {
            anc[v][0] = u;
            dep[v] = dep[u] + 1;
            precalc(v);
            attDown[u] |= attDown[v];
        }
    }
}
void preLCA() {
    FOR(j, 1, 20) FOR(u, 1, n) if ((1 << j) <= dep[u]) {
        anc[u][j] = anc[anc[u][j-1]][j-1];
        //cerr << u << " " << j << " " << anc[u][j] << "\n";
    }

}
int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    FORD(j, 20, 0) if ((1 << j) <= dep[v] - dep[u]) v = anc[v][j];
    if (u == v) return u;
    FORD(j, 20, 0) if ((1 << j) <= dep[u] && anc[u][j] != anc[v][j])
        u = anc[u][j], v = anc[v][j];
    return anc[u][0];
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(z, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i, 1, m) {
        int u;
        scanf("%d", &u);
        att[u] = 1;
        root = u;
    }
    if (m == 1) {
        printf("%d\n0", root);
        return 0;
    }
    findFar(root, node1, d);
    findFar(node1, node2, d);
    printf("%d")
}

