#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "message"
const int N = 1e5 + 5;
int n, m, res, vtx, scc;
int degIn[N], num[N], low[N], root[N], id[N];
vector<int> adj[N], ans;
ii e[N];
stack<int> st;
bool onStack[N];

void tarjan(int u) {
    //printf("tarjan %d\n", u);
    num[u] = low[u] = ++ vtx;
    st.push(u); onStack[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!num[v]) tarjan(v);
        if (onStack[v]) low[u] = min(low[u], low[v]);
    }
    if (num[u] == low[u]) {
        //cerr << "pop stack\n";
        scc ++;
        root[scc] = u;
        while (1) {
            int v = st.top(); st.pop();
            id[v] = scc;
            onStack[v] = 0;
            if (u == v) break;
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        e[i] = mp(u, v);
    }
    FOR(i, 1, n) if (!num[i]) tarjan(i);
    //FOR(i, 1, n) cerr << id[i] << "\n";
    FOR(i, 1, m) {
        int u = e[i].fi;
        int v = e[i].se;
        if (id[u] != id[v]) degIn[id[v]] ++;
    }
    FOR(i, 1, scc) if (degIn[i] == 0) ans.pb(root[i]);
    printf("%d\n", (int)ans.size());
    REP(i, ans.size()) printf("%d ", ans[i]);
}
/** Happy Coding :D */
