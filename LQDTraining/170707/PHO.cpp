using namespace std;
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

const int N = 1e5 + 50;

vector<int> adj[N];
int sign[N], mark[N], d[N];
long long res, maxc, tmp, mut, maxd;

void check(int u) {
    sign[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (sign[v] == 0) {
            check(v);
            mark[u] = max(mark[u], (int)(mark[v] > 0));
        }
    }
}

void dfs(int u) {
    sign[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (sign[v] == 0 && mark[v]>0) {
            res += 2;
            dfs(v);
            /*tmp ++;
            maxc = max(maxc, tmp);
            if (mark[v] == 2) tmp = 0, mark[v] == 1;

            tmp ++;
            maxc = max(maxc, tmp);*/
        }
    }
}

void dfs2(int u) {
    sign[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (sign[v] == 0 && mark[v] > 0) {
            d[v] = d[u] + 1;
            if (maxd < d[v]) maxd = d[v], mut = v;
            dfs2(v);
        }
    }
}
int main() {

    freopen("pho.inp", "r", stdin);
    freopen("pho.out", "w", stdout);

    int n, m, s;
    scanf("%d %d", &n, &m);

    memset(mark, 0, sizeof mark);
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        if (i == 1) s = x;
        mark[x] = 2;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(sign, 0, sizeof sign);
    check(s);

    memset(sign, 0, sizeof sign);
    dfs(s);

    memset(sign, 0, sizeof sign);
    maxd = 0; d[s] = 0;
    dfs2(s);
    //cout << maxd << endl;

    memset(sign, 0, sizeof sign);
    maxd = 0; d[mut] = 0;
    dfs2(mut);

    //cout << res <<endl;
    cout << res - maxd;
}
