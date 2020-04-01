using namespace std;
#include <stdio.h>
#include <vector>
#include <string.h>

const int N = 200;

vector<int> adj[N];
int sign[N], p[N];
bool yes;


void dfs(int u) {
    //printf("dfs %d\n", u);
    if (!yes) return;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v != p[u])
        if (sign[v] == -1) sign[v] = 1 - sign[u], p[v] = u, dfs(v);
        else if (sign[v] == sign[u]) yes = 0;
    }
}

int main () {
    int n;
    while (scanf("%d", &n)) {
        if (!n) break;

        for (int i = 0; i <= n; i++) adj[i].clear(), p[i] = i;
        memset(sign, -1, sizeof sign);

        int m;
        scanf("%d", &m);
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        yes = 1;

        for (int i = 0; i < n; i++) {
            if (sign[i] == -1) sign[i] = 0, dfs(i);
            //printf("%d\n", sign[i]);
            }

        if (!yes) printf("-1\n");
        else printf("res\n");

    }
}
