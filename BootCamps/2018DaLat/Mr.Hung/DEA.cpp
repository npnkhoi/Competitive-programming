using namespace std;
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define mp make_pair
#define fi first
#define se second
const int N = 1010;
const long long oo = 1e15 + 10;
int n, m, s, t, par[N];
long long res;
pair<long long, long long> a[N][N];
vector<int> adj[N], ans;
bitset<N> vis;
int main() {
    freopen("DEA.inp", "r", stdin);
    freopen("DEA.out", "w", stdout);
    scanf("%d%d", &n, &m);
    s = 1; t = n;
    REP(z, m) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        if (u == v) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
        a[u][v] = mp(c, z+1);
        a[v][u] = mp(c, z+1);
    }
    while (1) {
        vis.reset(); vis[s] = 1;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            REP(j, adj[u].size()) {
                int v = adj[u][j];
                if (vis[v] || a[u][v].fi <= 0) continue;
                vis[v] = 1; par[v] = u; q.push(v);
            }
        }
        if (vis[t]) {
            long long tmp = oo;
            int v = t;
            int save;
            while (v != s) {
                if (a[par[v]][v].fi < tmp) {
                    tmp = a[par[v]][v].fi;
                    save = a[par[v]][v].se;
                }
                v = par[v]/*, cout << v << " "*/;
            }
            res += tmp;
            ans.push_back(save);
            v = t;
            while (v != s) a[par[v]][v].fi -= tmp, a[v][par[v]].fi += tmp, v = par[v];
        }
        else break;
    }
    printf("%lld\n", res);
    REP(i, ans.size()) printf("%d ", ans[i]);
}
