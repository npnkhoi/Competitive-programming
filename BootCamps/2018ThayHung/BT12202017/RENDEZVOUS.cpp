#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define taskname "rendezvous"
const int N = 2e5 + 5;
const int LOG = 20;

int n, k;
int anc[N][LOG], dep[N];
vector<int> adj[N];
bool mark[N];

void dfs(int u) {
    mark[u] = 1;
    for (int i = 0 ; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (mark[v] == 0) {
            anc[v][0] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    }
}
void initLCA() {
    for (int i = 1; (1 << i) <= n; i++) {
        for (int u = 1; u <= n; u++)
        if ((1 << i) <= dep[u])
            anc[u][i] = anc[anc[u][i-1]][i-1];
    }
}
int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    while (dep[u] < dep[v])
        v = anc[v][(int)floor(log2(dep[v] - dep[u]))];
    if (u == v) return u;

    for (int i = LOG; i >= 0; i --)
    if ((1 << i) <= dep[u] && anc[u][i] != anc[v][i]) {
        u = anc[u][i];
        v = anc[v][i];
    }
    return anc[u][0];
}
int main() {
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n-1; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1);
    initLCA();
    while (k --) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", LCA(u, v));
    }
}
