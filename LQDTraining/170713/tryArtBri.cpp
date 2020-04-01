void dfs(int u) {
    num[u] = low[u] = ++cnt;

    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (num[v] == 0) {
            p[v] = u;
            rootChild += u == root;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (u != p[v]) low[u] = min (low[u], num[v]);
    }
}
