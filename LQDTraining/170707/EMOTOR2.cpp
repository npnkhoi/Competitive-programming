using namespace std;

void dfs(int u) {
    sign[u]
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d %d", &n, &m, &q);
        for (int i = 1; i <= n; i++) adj[i].clear();

        while (m--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        while (q--) {
            scanf("%d %d", &u, &d);
            memset(sign, 0, sizeof sign);
            res = 0;
            printf("%d\n", range(u, d));
        }
    }
}
