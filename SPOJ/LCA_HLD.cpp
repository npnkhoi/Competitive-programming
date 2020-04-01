#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#define REP(i, n) for (int i = 0; i < n; i ++)
using namespace std;
const int N = 1e3 + 5;
int tc, n, q, idx;
int mark[N], cnt[N], par[N], head[N], dep[N], num[N];
vector<int> adj[N];
void dfs(int u) {
    //printf("dfs %d\n", u);
    cnt[u] = 1;
    num[u] = ++ idx;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (num[v] == 0) {
            par[v] = u;
            dfs(v);
            cnt[u] += cnt[v];
        }
    }
}
void HLD(int u) {
    //printf("HLD %d\n", u);
    int w = -1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v != par[u] && (w == -1 || cnt[v] > cnt[w])) w = v;
    }
    if (w != -1) {
        head[w] = head[u];
        dep[w] = dep[u];
        HLD(w);
    }
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v != w && v != par[u] && head[v] == 0) {
            dep[v] = dep[u] + 1;
            head[v] = v;
            HLD(v);
        }
    }
}
int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    while (dep[u] < dep[v]) v = par[head[v]];
    while (head[u] != head[v])
        u = par[head[u]], v = par[head[v]];
    if (num[u] < num[v]) return u;
    else return v;
}
int main() {
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            REP(j, x) {
                int u;
                scanf("%d", &u);
                adj[i].push_back(u);
                adj[u].push_back(i);
            }
        }
        idx = 0;
        memset(num, 0, sizeof num);
        dfs(1);
        memset(head, 0, sizeof head);
        head[1] = 1; dep[1] = 1;
        //for (int i = 1; i <= n; i++) cerr << cnt[i] << " "; cerr << endl;
        HLD(1);
        //for (int i = 1; i <= n; i++) cerr << head[i] << " "; cerr << endl;
        //for (int i = 1; i <= n; i++) cerr << dep[i] << " "; cerr << endl;
        printf("Case %d:\n", khue + 1);
        scanf("%d", &q);
        REP(z, q) {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", LCA(u, v));
        }
    }
}
