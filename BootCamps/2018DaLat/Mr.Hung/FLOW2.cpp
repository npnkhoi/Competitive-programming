using namespace std;
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define fi first
#define se second
const int N = 1e4 + 1;
const int M = 1e5 + 5;
const long long oo = 1e15 + 10;
int n, m, s, t, par[N];
long long res, a[N][N], f[N][N];
vector<int> adj[N];
bitset<N> vis;
pair<int, int> e[M];
int main() {
    freopen("FLOW.inp", "r", stdin);
    freopen("FLOW.out", "w", stdout);
    scanf("%d %d %d %d", &n, &m, &s, &t);
    REP(z, m) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        if (u == v) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
        a[u][v] = c;
        e[z] = make_pair(u, v);
    }
    while (1) {
        vis.reset(); vis[s] = 1;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            REP(j, adj[u].size()) {
                int v = adj[u][j];
                if (vis[v] || a[u][v] <= 0) continue;
                vis[v] = 1; par[v] = u; q.push(v);
            }
        }
        if (vis[t]) {
            long long tmp = oo;
            int v = t;
            while (v != s) tmp = min(tmp, a[par[v]][v]), v = par[v]/*, cout << v << " "*/;
            res += tmp;
            v = t;
            while (v != s) {
                a[par[v]][v] -= tmp;
                a[v][par[v]] += tmp;
                f[par[v]][v] += tmp;
                v = par[v];
            }
        }
        else break;
    }
    printf("%lld\n", res);
    REP(i, m) printf("%lld\n", f[e[i].fi][e[i].se]);
}
