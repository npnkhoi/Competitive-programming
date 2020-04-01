#include <cstdio>
using namespace std;

void dfs1(int u) {

}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) if (!mark[i]) {
        CCs ++;
        dfs1(1);
    }
    for (int i = 1; i <= n; i++) if (!mark[])


}
