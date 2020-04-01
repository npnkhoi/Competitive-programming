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
#define taskName "jobset"
const int N = 505;
int n, m, vtx, scc;
vector<int> adj[N], dag[N], topo;
vector<ii> newEdge;
int a[N], num[N], low[N], id[N];
ll w[N];
stack<int> st;
bool onStack[N], mark[N];


void tarjan(int u) {
    num[u] = low[u] = ++ vtx;
    st.push(u); onStack[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!num[v]) tarjan(v);
        if (onStack[v]) low[u] = min(low[u], low[v]);
    }
    if (num[u] == low[u]) {
        scc ++;
        while (1) {
            int v = st.top(); st.pop();
            id[v] = scc;
            w[scc] += a[v];
            onStack[v] = 0;
            if (u == v) break;
        }
    }
}
void topoSort(int u) {
    mark[u] = 1;
    REP(j, dag[u].size()) {
        int v = dag[u][j];
        if (mark[v] == 0) topoSort(v);
    }
    topo.pb(u);
}
int main() {
    freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    scanf("%d", &m);
    REP(i, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
    }
    cerr << "part1\n";
    FOR(u, 1, n) if (num[u] == 0) tarjan(u);
    FOR(i, 1, n) cerr << i << " " << id[i] << "\n";
    cerr << "ok2\n";

    FOR(u, 1, n) REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (id[u] != id[v]) newEdge.pb(mp(id[u], id[v]));
    }

    sort(newEdge.begin(), newEdge.end());
    cerr << "ok3\n";
    REP(i, newEdge.size())
    if (i == 0 || newEdge[i] != newEdge[i-1]) {
        dag[newEdge[i].fi].pb(newEdge[i].se);
    }
    FOR(i, 1, scc) if (dag[i].size() == 0) dag[i].pb(scc+1); /// virtual vtx
    scc ++;
    cerr << "ok4\n";
    FOR(i, 1, scc) if (mark[i] == 0) topoSort(i);
    cerr << "ok5\n";
    reverse(topo.begin(), topo.end());
    FOR(i, 1, scc) {
        printf("%d: %lld\n", i, w[i]);
        REP(j, dag[i].size()) printf("%d ", dag[i][j]);
        cerr << "\n";
    }
    REP(i, scc) {
        int u = topo[i];
        cerr << u << " " << w[u] << "\n";
        if (w[u] > 0) REP(j, dag[u].size()) {
            int v = dag[u][j];
            w[v] += w[u];
        }
    }
    printf("%lld\n", w[scc]);
    return 0;
}
/** Happy Coding :D */
