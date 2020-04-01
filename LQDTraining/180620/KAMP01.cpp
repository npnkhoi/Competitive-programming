#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "KAMP01"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 5e5 + 5;
int n, k;
vector<ii> adj[N];
int cur[N], cntCur[N], mark[N], par[N];
ll gold[N], res;

void dfs(int u) {
    //cerr << "dfs " << u << "\n";
    mark[u] = 1;
    cntCur[u] = cur[u];
    REP(j, adj[u].size()) {
        int v = adj[u][j].fi;
        int c = adj[u][j].se;
        if (!mark[v]) {
            par[v] = u;
            dfs(v);
            cntCur[u] += cntCur[v];
            gold[u] += c + gold[v];
        }
    }
    //cerr << "inf of vtx " << u << " " << cntCur[u] << " " << gold[u] << "\n";
    REP(j, adj[u].size()) {
        int v = adj[u][j].fi, c = adj[u][j].se;
        if (v != par[u] && cntCur[u] > 0 && cntCur[v] == 0) {
            res -= c + gold[v];
            //cerr << "del " << v << " " << cntCur[v] << "\n";
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i, 1, n-1) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
        res += c;
    }
    int root;
    FOR(i, 1, k) {
        int u;
        scanf("%d", &u);
        cur[u] = 1;
        root = u;
    }
    //cerr << root << "\n";
    dfs(root);
    printf("%lld", res);
}
