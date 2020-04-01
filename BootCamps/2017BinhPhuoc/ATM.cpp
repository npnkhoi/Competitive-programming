#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

#define taskName "ATM"

const int N = 5e5 + 5;
int n, m, vtx, scc;
vector<int> adj[N], _adj[N], topo;
bool End[N], _End[N], vis[N], mark[N], reach[N];
int num[N], low[N], id[N], a[N];
ll dp[N], w[N];
stack<int> st;

void tarjan(int u) {
    //printf("tarjan %d\n", u);
    num[u] = low[u] = ++ vtx;
    vis[u] = 1;
    st.push(u);
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (num[v] == 0) tarjan(v);
        if (vis[v]) {
            low[u] = min(low[u], low[v]);
            //printf("%d -> %d: %d\n", u, v, low[u]);
        }
    }
    if (num[u] == low[u]) {
        //printf("root: %d\n", u);
        scc ++;
        while (1) {
            int v = st.top(); st.pop();
            vis[v] = 0;
            id[v] = scc;
            w[scc] += a[v];
            _End[scc] |= End[v];
            //printf("%d ", v);
            if (u == v) break;
        }
        //cerr << "\n";
    }
}
void dfs(int u) {
    mark[u] = 1;
    REP(j, _adj[u].size()) {
        int v = _adj[u][j];
        if (mark[v] == 0) dfs(v);
    }
    topo.push_back(u);
}
int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    //-------------------------------------
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
    /*FOR(i, 1, n) {
        cerr << i << " : ";
        REP(j, adj[i].size()) cerr << adj[i][j] << " ";
        cerr << "\n";
    }*/
    FOR(i, 1, n) scanf("%d", &a[i]);
    int s, p;
    scanf("%d%d", &s, &p);
    FOR(i, 1, p) {
        int val;
        scanf("%d", &val);
        End[val] = 1;
    }
    //--------------------------------------
    vtx = 0; scc = 0;
    FOR(u, 1, n) if (num[u] == 0) tarjan(u);
    //FOR(u, 1, n) printf("vtx(%d): %d %d %d\n", u, num[u], low[u], id[u]);

    FOR(u, 1, n) REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (id[u] != id[v]) {
            _adj[id[u]].push_back(id[v]);
        }
    }
    /*FOR(i, 1, scc) {
        printf("SCC %d: %lld\nEnd: ", i, w[i]);
        cerr << _End[i] << "\n";

        REP(j, _adj[i].size()) printf("%d ", _adj[i][j]);
        cerr << "\n";
    }*/
    //cerr << "ok\n";
    FOR(i, 1, scc) if (mark[i] == 0) dfs(i);
    reverse(topo.begin(), topo.end());
    /*cerr << "Topo order: \n";
    REP(i, topo.size()) printf("%d ", topo[i]);
    cerr << "\n";
    //dp[id[s]] = w[id[s]];
    cerr << "dp\n";
    FOR(i, 1, scc) cerr << dp[i] << " "; cerr << "\n";*/
    ll res = 0;
    reach[id[s]] = 1;
    REP(i, scc) {
        int u = topo[i];
        //cerr << u << "\n";
        if (reach[u]) {
            dp[u] += w[u];
            if (_End[u]) res = max(res, dp[u]);
            //cerr << "-> ";
            REP(j, _adj[u].size()) {
                int v = _adj[u][j];
                //cerr << v << " ";
                dp[v] = max(dp[v], dp[u]);
                reach[v] = 1;
            }
            //cerr << "\n";
        }
    }
    printf("%lld", res);
    return 0;
}
/** Happy Coding :D */
