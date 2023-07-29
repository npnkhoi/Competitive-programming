#include <bits/stdc++.h>
using namespace std;

const int LOG = 10, N = 1005;

int n, m, cntTree = 0;
int a[N], anc[N][LOG + 2], tree[N], path[N], degIn[N], degOut[N], depth[N];
vector<int> adj[N];


void dfs(int u) {
    // path, depth, anc, tree
    tree[u] = cntTree;
    for (int d = 1; (1 << d) <= depth[u]; d++) {
        anc[u][d] = anc[anc[u][d-1]][d-1];
    }

    for (int v : adj[u]) {
        depth[v] = depth[u] + 1;
        anc[v][0] = u;
        path[v] = path[u] + a[v];

        dfs(v);
    }
}

int lca(int u, int v) {
    // v must be lower
    if (depth[v] < depth[u]) swap(u, v);

    // make them same height
    for (int d = LOG; d >= 0; --d) {
        if (((depth[v] - depth[u]) >> d) > 0) {
            v = anc[v][d];
        }
    }

    if (u == v) return u;

    for (int d = LOG; d >= 0; --d) {
        if ((depth[u] >> d) > 0 && (anc[u][d] != anc[v][d])) {
            u = anc[u][d];
            v = anc[v][d];
        }
    }
    return anc[u][0];
}

int main() {
    // freopen("test.inp", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++ i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        degIn[v] ++;
        degOut[u] ++;
    }
    for (int u = 1; u <= n; ++ u) {
        if (degIn[u] == 0) {
            cntTree ++;
            path[u] = a[u];
            dfs(u);
        }
    }

    int res = 1e9;

    for (int i = 1; i < n; ++ i) {
        if (degOut[i] != 0) continue;
        for (int j = i + 1; j <= n; ++ j) {
            if (degOut[j] != 0) continue;

            // printf("from %d and %d\n", i, j);

            int tmp = path[i] + path[j];
            if (tree[i] == tree[j]) {
                int k = lca(i, j);
                tmp -= path[k];
                // printf("lca = %d\n", k);
            }
            // printf("cost = %d\n", tmp);

            res = min(res, tmp);
        }
    }
    cout << res << '\n';
}
