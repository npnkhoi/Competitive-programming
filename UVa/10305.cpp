using namespace std;
#include <vector>
#include <stdio.h>
#include <string.h>

const int N = 110;

vector<int> adj[N];
bool sign[N];
vector<int> ans;


void dfs(int u) {
    //printf("%d\n", u);
    sign[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (sign[v] == 0) dfs(v);
    }
    ans.push_back(u);
}
int main() {
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (!m && !n) break;
        for (int i =1 ; i <= n; i++) adj[i].clear();

        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }
        //-------
        ans.clear();
        memset(sign, 0, sizeof sign);

        for (int i = 1; i <= n; i++) if (!sign[i]) dfs(i);
        for (int i = n-1; i >= 0; i--) printf("%d ", ans[i]);
        printf("\n");

    }
}
