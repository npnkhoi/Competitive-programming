using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 2e5 + 5;
int anc[22][N];
bool sign[N];
ii vtx[N];
int n, k, res[N], dep[N], lab[N];
vector<int> adj[N];
void init(int u) {
    sign[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (sign[v] == 0) {
            anc[0][v] = u;
            dep[v] = dep[u] + 1;
            init(v);
        }
    }
}
void preLCA() {
    for (int i = 1; (1<<i) <= n; i++)
    for (int u = 1; u <= n; u++)
    if ((1 << i) <= dep[u]) anc[i][u] = anc[i-1][anc[i-1][u]];
}
int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    while (dep[u] < dep[v]) v = anc[int(floor(log2(dep[v] - dep[u])))][v];
    if (u == v) return u;
    for (int i = int(floor(log2(dep[u]))); i >= 0; i--)
    if ((1 << i) <= dep[u] && anc[i][u] != anc[i][v]) {
        u = anc[i][u];
        v = anc[i][v];
    }
    return anc[0][u];
}
int dist(int u, int v) {
    int t = LCA(u, v);
    return dep[v] + dep[u] - 2 * dep[t];
}
void dfs(int u) {
    sign[u] = 1;
    int l = lab[u];
    int x = vtx[l].fi;
    int y = vtx[l].se;
    if (x == -1) vtx[l].fi = u;
    else if (y == -1) {
        vtx[l].se = u;
        res[l] = dist(u, x);
    }
    else {
        if (res[l] < dist(x, u)) {
            res[l] = dist(x, u);
            vtx[l] = mp(x, u);
        }
        if (res[l] < dist(y, u)) {
            res[l] = dist(y, u);
            vtx[l] = mp(y, u);
        }
    }
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (sign[v] == 0) dfs(v);
    }
}

int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &n, &k);
    int x, y;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        lab[i] = x;
        if (y) {
            adj[i].push_back(y);
            adj[y].push_back(i);
        }
    }
    dep[1] = 0;
    init(1);
    preLCA();
    memset(sign, 0, sizeof sign);
    memset(vtx, -1, sizeof vtx);
    dfs(1);
    for (int i = 1; i <= k; i++) printf("%d\n", res[i]);
    return 0;
}
/** Happy Coding ^^ */
