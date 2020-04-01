using namespace std;
#include <stdio.h>
#include <vector>
const int N = 1e5 + 10;
vector<int> adj[N];
int par[N], d[N];
bool cont;

void dfs(int u) {
    for (int j = 0; j < adj[u].size() && cont; j++) {
        int v = adj[u][j];
        if (d[v] == 0) {
            par[v] = u;
            d[v] = d[u] + 1;
            dfs(v);
        }
        else if (cont && d[u] - d[v] == 3 && par[par[par[u]]] == v) {
            printf("%d %d %d %d\n", u, par[u], par[par[u]], v);
            cont = 0;
        }
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m --) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cont = 1;
    for (int i = 1; i <= n && cont; i++) if (d[i] == 0) {
        d[i] = 1;
        dfs(i);
    }
    if (cont) printf("-1");
}
