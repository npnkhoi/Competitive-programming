using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int N = 2e5 + 5;
const ll md = 1e9 + 7;
int num[N], low[N], cnt[N], deg[N], par[N], tp[N];
int n, m, idx;
bool vis[N];
vector<int> adj[N];
set<ii> bridge;

void dfs(int u) {
    num[u] = low[u] = ++ idx;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (num[v] == 0) {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);

            if (low[v] > num[u]) {
                bridge.insert(mp(u, v));
            }
        }
        else if (v != par[u])
            low[u] = min(low[u], num[v]);
    }
}
bool isBridge(int u, int v) {
    return  bridge.find(mp(u, v)) != bridge.end()
            || bridge.find(mp(v, u)) != bridge.end();
}
void findComponent(int u) {
    ++ cnt[tp[u]];
    vis[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (vis[v] == 0) {
            if (isBridge(u, v)) {
                ++ deg[tp[u]];
                tp[v] = ++ idx;
                ++ deg[tp[v]];
            } else tp[v] = tp[u];
            findComponent(v);
        }
    }
}

int main() {
    freopen("DATA.inp", "r", stdin);
    freopen("DATA.out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(z, m) {
        int u, v, c;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    idx = 0;
    dfs(1);
    idx = 1;
    memset(vis, 0, sizeof vis);
    tp[1] = 1;
    findComponent(1);

    if (idx == 1) {
        printf("1 %d\n", cnt[1]);
    } else {
        int res1 = 0;
        ll res2 = 1;
        FOR(i, 1, idx) if (deg[i] == 1) {
            ++ res1;
            res2 = (res2 * cnt[i]) % md;
        }
        printf("%d %lld\n", res1, res2);
    }
    return 0;
}
/** Happy Coding ^^ */

