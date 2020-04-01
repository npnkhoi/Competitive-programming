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

#define taskName "0"

const int N = 1005;
const int M = 2e4 + 5;
vector<int> adj[N], adj2[N], newVtx;
vector<ii> edge2, ans;
ii e[M];
int num[N], low[N], vtx;
stack<int> st;
bool vis[N];
int n, m;

bool ok;

void tarjan(int u) {
    low[u] = num[u] = ++ vtx;
    vis[u] = 1;
    st.push(u);

    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (num[v] == 0) tarjan(v);
        if (vis[v]) low[u] = min(low[u], low[v]);
    }
    if (num[u] == low[u]) {
        vi tmp;
        while (1) {
            int v = st.top(); st.pop();
            tmp.pb(v); vis[v] = 0;
            if (u == v) break;
        }
        if (tmp.size() > 1) {
            if (newVtx.empty()) newVtx = tmp;
            else {
                printf("-1");
                exit(0);
            }
        }
    }
}
void dfs(int u, int X, int Y) {
    num[u] = -1;
    REP(j, adj2[u].size()) {
        int v = adj2[u][j];
        if (u == X && v == Y) continue;
        if (num[v] == 0) {
            dfs(v, X, Y);
        } else if (num[v] == -1) ok = 0;
    }
    num[u] = 1;
}
bool inVec(int val, vi &v) {
    int pos = upper_bound(v.begin(), v.end(), val) - v.begin() - 1;
    return v[pos] == val;
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        scanf("%d%d", &e[i].fi, &e[i].se);
        adj[e[i].fi].push_back(e[i].se);
    }
    FOR(i, 1, n) if (num[i] == 0) tarjan(i);
    if (newVtx.empty()) {
        printf("-1");
        exit(0);
    }
    //cerr << "ai1\n";
    //REP(i, newVtx.size()) cerr << newVtx[i] << "\n";
    sort(newVtx.begin(), newVtx.end());
    REP(i, m) {
        int u = e[i].fi;
        int v = e[i].se;
        if (inVec(u, newVtx) && inVec(v, newVtx)) {
            adj2[u].push_back(v);
            //printf("%d -> %d\n", u, v);
            edge2.pb(e[i]);
        }
    }
    REP(z, edge2.size()) {
        int u = edge2[z].fi, v = edge2[z].se;
        memset(num, 0, sizeof num);
        ok = 1; /// global var
        REP(t, newVtx.size()) {
            int x = newVtx[t];
            if (num[x] == 0) dfs(x, u, v);
        }
        if (ok) ans.pb(edge2[z]);
    }
    if (ans.empty()) printf("-1");
    else {
        printf("%d\n", (int)ans.size());
        sort(ans.begin(), ans.end());
        REP(j, ans.size()) printf("%d %d\n", ans[j].fi, ans[j].se);
    }
    return 0;
}
/** Happy Coding :D */
