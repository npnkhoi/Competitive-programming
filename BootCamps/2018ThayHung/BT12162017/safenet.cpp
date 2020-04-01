#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define task "safenet"
#define fi first
#define se second
#define mp make_pair
const int N = 1e5 + 5;
int n, m, num[N], low[N], par[N], mark[N];
int idx, cnt, res, save, vtx;
bool art[N], root[N];
vector<int> adj[N];
pair<int, int> e[N];

void check(int u) {
    int tmp = 0;
    num[u] = low[u] = ++ vtx;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (num[v] == 0) {
            par[v] = u;
            check(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]) {
                art[u] = 1;
                tmp ++;
            }
        } else if (par[u] != v) low[u] = min(low[u], num[v]);
    }
    if (root[u]) art[u] = (tmp >= 2);
}
void dfs(int u) {
    //printf("dfs %d\n", u);
    mark[u] = idx; cnt ++;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (mark[v] == 0 && art[v] == 0) dfs(v);
        else if (art[v] && mark[v] != idx) {
            mark[v] = idx;
            cnt ++;
        }
    }
}
void ans(int u) {
    mark[u] = 1;
    printf("%d ", u);
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (mark[v] == 0) {
            if (art[v] == 0) ans(v);
            else {
                mark[v] = 1;
                printf("%d ", v);
            }
        }
    }
}
int main() {
    freopen(task".inp" ,"r", stdin);
    freopen(task".out" ,"w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        e[i] = mp(u, v);
        //adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    sort(e, e+m);
    for (int i = 0; i < m; i++) if (i == 0 || e[i] != e[i+1]) {
        adj[e[i].fi].push_back(e[i].se);
        adj[e[i].se].push_back(e[i].fi);
    }
    for (int i = 1; i <= n; i++) if (num[i] == 0) {
        root[i] = 1;
        check(i);
    }
    for (int i = 1; i <= n; i++) if (mark[i] == 0 && !art[i]) {
        cnt = 0;
        idx ++;
        dfs(i);
        if (cnt > res) {
            res = cnt;
            save = i;
        }
    }
    if (res == 0) {
        printf("1\n1\n");
    } else {
        printf("%d\n", res);
        //cerr << save << "\n";
        memset(mark, 0, sizeof mark);
        ans(save);
    }
}
