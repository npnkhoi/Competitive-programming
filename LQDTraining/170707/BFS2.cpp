using namespace std;

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(u);
        adj[v].push_back(v);
    }

    memset(num, 0, sizeof num);
    for (int i  = 1; i <= n; i++)  d[i] = oo;
    d[1] = 0;
    dfs(1); int _max = 0;
    for (int i = 1; i <= n; i++) _max = max(_max, d[i]);
    for (int i = 1; i <= n; i++) _max
}
