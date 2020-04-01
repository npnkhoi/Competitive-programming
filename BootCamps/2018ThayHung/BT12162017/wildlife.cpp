#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
#define task "wildlife"
#define fi first
#define se second
const int N = 1e5 + 5;
int m, n, par[N], road[N], t[N];
queue<int> q;
vector<pair<int, int> > adj[N];
bool bfs(int delta) {
    //printf("bfs %d\n", delta);
    memset(par, 0, sizeof par);
    while (!q.empty()) q.pop();
    q.push(1); par[1] = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == n) return 1;
        for (int j = 0; j < adj[u].size(); j++) {
            pair<int, int> v = adj[u][j];
            if (par[v.fi] == 0 && abs(t[u] - t[v.fi]) <= delta) {
                par[v.fi] = u;
                road[v.fi] = v.se;
                q.push(v.fi);
                //cerr << v.fi << "\n";
            }
        }
    }
    return 0;
}
void trace(int u) {
    //cerr << u << " " << par[u] << "\n";
    if (par[u] > 0) {
        trace(par[u]);
        printf("%d ", road[u]);
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(make_pair(v, i));
        adj[v].push_back(make_pair(u, i));
    }
    int l = 0, r = (int)2e9, d = r;
    while (l <= r) {
        int mi = (l+r)/2;
        if (bfs(mi)) {
            d = min(d, mi);
            r = mi - 1;
        } else l = mi + 1;
    }
    printf("%d\n", d);
    bfs(d);
    //cerr << "\n";
    trace(n);
}
