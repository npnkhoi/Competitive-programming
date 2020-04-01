using namespace std;
#include <stdio.h>
#include <vector>
#include <string.h>

const int N = 1e5 + 10;
vector<int> adj[N];
int low[N], num[N], par[N], f[N];
int cnt, n, m;
bool art[N];

void dfs(int u) {
    num[u] = low[u] = ++cnt;
    f[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (!num[v]) {
            par[v] = u;

            dfs(v);

            if (low[v] >= num[u]) art[u] = 1;
            low[u] = min(low[u], low[v]);
            f[u] += f[v];
        }
        else if (v != par[u]) low[u] = min(low[u], num[v]);
    }
}

int main () {
    freopen("blo.inp", "r", stdin);
    freopen("blo.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cnt = 0;
    memset(num, 0, sizeof num);
    memset(art, 0, sizeof art);
    for (int i = 1; i <= n; i++) par[i] = i;

    dfs(1);
    /*for (int i = 1; i <= n; i++) {
        for (int j = 0; j < adj[i].size(); j++) printf("%d ", adj[i][j]);
        printf("\n");
    }
    for (int i = 1; i <= n; i++) printf("%d ", low[i]); printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", num[i]); printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", f[i]); printf("\n");*/

    int u = 1; cnt = 0;

    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (par[v] == u) cnt ++;
    }

    if (cnt == 1) printf("%d\n", 2*(n-1));
    else {
        long long res = n-1;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (par[v] == u) res += 1LL * f[v] * (n - f[v]);
        }
        printf("%lld\n", res);
    }

    for (int u = 2; u <= n; u++)
        if (!art[u]) printf("%d\n", 2*(n-1));
        else {
            long long res = n-1;
            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j];
                if (par[v] == u && low[v] >= num[u])
                    //printf("%d(%d) ", f[v], v),
                    res += 1LL * f[v] * (n - f[v]);
            }
            if (u != 1) {
                int x = 1;
                for (int j = 0; j < adj[u].size(); j++) {
                    int v = adj[u][j];
                    if (par[v] == u && low[v] >= num[u]) x += f[v];
                }
                res += 1LL * x * (n-x)
                //, printf("%d(%d) ", x, u)
                ;
            }
            printf("%lld\n", res);
        }
}
