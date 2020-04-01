using namespace std;
#include <vector>
#include <stdio.h>
#include <string.h>
const int N = 1e5 + 10;
int n, m, k, l;
vector<int> adj[N];
int num[N], low[N], p[N], cnt, res = 0;
int a[N], b[N];
void dfs(int u) {
    num[u] = low[u] = ++cnt;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (num[v] == 0) {
            p[v] = u;
            dfs(v);
            a[u] += a[v];
            b[u] += b[v];
            if (low[v] > num[u])
                res += (k == a[v] || a[v] == 0 || l == b[v] || b[v] == 0);
            low[u] = min(low[u], low[v]);
        }
        else if (v != p[u]) low[u] = min(low[u], num[v]);
    }
}
int main() {
    freopen("net.inp", "r", stdin);
    freopen("net.out", "w", stdout);
    scanf("%d %d %d %d", &n, &m, &k, &l);
    int u;
    for (int i = 1; i <= k; i++) scanf("%d", &u), a[u] = 1;
    for (int i = 1; i <= l; i++) scanf("%d", &u), b[u] = 1;
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(num, 0, sizeof num);
    memset(low, 0, sizeof low);
    dfs(1);
    printf("%d", res);
}
