#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2000;
int n, m, idx, cntRoot, num[N], low[N], par[N];
bool art[N];
vector<int> adj[N], ans;
void dfs(int u) {
    num[u] = low[u] = ++ idx;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (num[v] == 0) {
            par[v] = u;
            dfs(v);
            if (low[v] >= num[u]) art[u] = 1;
            if (u == 1) cntRoot ++;
            low[u] = min(low[u], low[v]);
        } else if (v != par[u]) low[u] = min(low[u], num[v]);
    }
}
int main() {
    freopen("CITY.inp", "r", stdin);
    freopen("CITY.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) cerr << num[i] << " "; cerr << "\n";
    for (int i = 1; i <= n; i++) cerr << low[i] << " "; cerr << "\n";
    art[1] = (cntRoot > 1);
    for (int i = 1; i <= n; i++) if (art[i]) ans.push_back(i);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);

}
