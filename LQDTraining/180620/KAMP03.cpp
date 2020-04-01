#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "KAMP03"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 5e5 + 5;
int n, k;
vector<ii> adj[N];
int inTree[N], mark[N], par[N];
pair<li, li> maxAll[N];
li maxDown[N];


void update(li a, pair<li, li> &b) {
    if (a > b.fi) b.se = b.fi, b.fi = a;
    else if (a > b.se) b.se = a;
}
void dfs1(int u, int par) {
    REP(j, adj[u].size()) {
        int v = adj[u][j].fi;
        int c = adj[u][j].se;
        if (v != par) {
            dfs1(v, u);
            if (inTree[v]) {
                inTree[u] = 1;
                maxDown[u] = max(maxDown[u], mp(c + maxDown[v].fi, v));
                update(mp(c + maxDown[v].fi, v), maxAll[u]);
            }
        }
    }
    //cerr << u << " " << inTree[u] << " " << maxDown[u].fi << " " << maxDown[u].se << "\n";
}
void dfs2(int u, int par) {
    REP(j, adj[u].size()) {
        int v = adj[u][j].fi;
        int c = adj[u][j].se;
        if (v != par && inTree[v]) {
            ii tmp = maxAll[u].fi;
            if (maxAll[u].fi.se == v) tmp = maxAll[u].se;
            update(mp(tmp.fi + c, u), maxAll[v]);
            dfs2(v, u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> k;
    FOR(i, 1, n-1) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
    }
    int root;
    FOR(i, 1, k) {
        int u;
        cin >> u;
        inTree[u] = 1;
        root = u;
    }
    //cerr << root << "\n";
    dfs1(root, -1);
    dfs2(root, -1);
    FOR(i, 1, n)
        //printf("%lld\n", dist[i]);
        cout << maxAll[i].fi.fi << '\n';
}
