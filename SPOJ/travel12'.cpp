using namespace std;
#include <stdio.h>
#include <vector>
#include <cstring>
const int N = 1e4 + 10;
vector<int> adj[N];
int par[N], sign[N];
bool mat[N][N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (m --) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (mat[u][v] || u == v) continue;
        mat[u][v] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        memset(par, 0, sizeof par);
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            for (int k = 0; k < adj[v].size(); k++) {
                int t = adj[v][k];
                if (t == u || t == v) continue;
                if (par[t] == 0) par[t] = v;
                else if (par[t] != v) {
                    printf("%d %d %d %d\n", u, v, t, par[t]);
                    return 0;
                }
            }
        }
    }
    printf("-1");
}
