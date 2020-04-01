#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3e5 + 5;
const int CHAR = 30;

int n, m;
vector<int> adj[N], topo;
int mark[N], a[N], dp[N][CHAR];

void dfs(int u) {
    mark[u] = -1;
    for (int j = 0; j < adj[u].size(); ++ j) {
        int v = adj[u][j];
        if (mark[v] == -1) {
            printf("-1");
            exit(0);
        } else if (mark[v] == 0) dfs(v);
    }
    mark[u] = 1;
    topo.push_back(u);
}
int main() {
    scanf("%d%d ", &n, &m);
    for (int i = 1; i <= n; i++) {
        char ch;
        scanf(" %c", &ch);
        a[i] = ch - 'a';
    }
    for (int i = 1; i <= m; ++ i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!mark[i]) dfs(i);
    reverse(topo.begin(), topo.end());

    int res = 0;

    for (int i = 0; i < n; i++) {
        int u = topo[i];
        //cerr << u << " ";
        dp[u][a[u]] ++;
        for (int j = 0; j < 26; j++) res = max(res, dp[u][j]);

        for (int j = 0; j < adj[u].size(); j ++) {
            int v = adj[u][j];
            for (int k = 0; k < 26; ++ k) dp[v][k] = max(dp[v][k], dp[u][k]);
        }
    }
    printf("%d", res);
}
