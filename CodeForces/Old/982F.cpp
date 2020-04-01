#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 5e3 + 5;
int n, m, s;
vi adj[N], topo;
int vis[N];

void topoSort(int u) {
    vis[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!vis[v]) topoSort(v);
    }
    topo.pb(u);
}
void dfs(int u) {
    vis[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (vis[v] == 0) {
            dep[v] = dep[u] + 1;
            dfs(v, d+1);
        }
        else if (vis[v] == 2) {
            backEdge.pb(mp(v, u));
        }
    }
    vis[u] = 2;
}
void marking(int u) {
    vis[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!vis[v]) marking(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n >> m;
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
    }
    FOR(i, 1, n) if (!vis[i]) topoSort(i);
    reverse(topo.begin(), topo.end());
    memset(vis, 0, sizeof vis);
    marking(topo[0]);
    FOR(i, 1, n) if (!vis[i]) {
        cout << "-1";
        exit(0);
    }
    int root = topo[0];
    memset(vis, 0, sizeof vis);
    dfs(root, 0);
    int top = 0, bot = n;
    REP(i, backEdge.size()) {
        top = max(top, backEdge[i].fi);
        bot = min(bot, backEdge[i].se);
        if (top > bot) {
            printf("-1");
            exit(0);
        }
    }

}
