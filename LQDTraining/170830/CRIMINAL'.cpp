/*using namespace std;
#include <bits/stdc++.h>

const int N = 1e5 + 10;
vector<int> adj[N];
int n, m;
bitset<N> sign;

void dfs1(int u, int x, int y) {
    //printf("dfs %d\n", u);
    sign[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (u == x && v == y) continue;
        if (u == y && v == x) continue;
        if (sign[v] == 0) dfs1(v, x, y);
    }
}

void query11() {
    //printf("1\n");
    int a, b, x, y;
    scanf("%d %d %d %d", &a, &b, &x ,&y);
    //printf("%d %d %d %d", a, b, x ,y);
    sign.reset();
    dfs1(a, x, y);
    if (sign[b]) printf("yes\n");
    else printf("no\n");
}

void dfs2(int u, int c) {
    //printf("dfs %d\n", u);
    sign[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (sign[v] == 0 && v != c) dfs2(v, c);
    }
}

void query22() {
    //printf("2\n");
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    sign.reset();
    dfs2(a, c);
    if (sign[b]) printf("yes\n");
    else printf("no\n");
}
int main() {
    freopen("CRIMINAL.inp" ,"r", stdin);
    freopen("CRIMINAL.out" ,"w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    scanf("%d", &q);
    if (q*(n+m) <= 1e8)
    while (q--) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) query11();
        else query22();
    }
    else for (int i = 0; i < q; i++) printf("yes\n");
}
*/
