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

#define taskName "NEWROADS"

const int N = 1e5 + 5;
int n, m, vtx, scc;
vector<int> adj[N];
int num[N], low[N], cntV[N], cntE[N], id[N];
bool vis[N];
stack<int> st;

void tarjan(int u) {
    //printf("tarjan %d\n", u);
    num[u] = low[u] = ++ vtx;
    vis[u] = 1;
    st.push(u);
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (num[v] == 0) tarjan(v);
        if (vis[v]) low[u] = min(low[u], low[v]);
    }
    if (num[u] == low[u]) {
        scc ++;
        while (1) {
            int v = st.top(); st.pop();
            vis[v] = 0;
            id[v] = scc;
            cntV[scc] ++;
            if (u == v) break;
        }
    }
}
int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
    FOR(u, 1, n) if (num[u] == 0) tarjan(u);
    FOR(u, 1, n) {
        sort(adj[u].begin(), adj[u].end());
        REP(j, adj[u].size()) if (j == 0 || adj[u][j] != adj[u][j-1]) {
            int v = adj[u][j];
            if (id[u] == id[v]) cntE[id[u]] ++;
        }
    }
    ll res = 0;
    FOR(i, 1, scc) res += 1LL * cntV[i] * (cntV[i] - 1) - cntE[i];
    printf("%lld", res);
    return 0;
}
/** Happy Coding :D */
