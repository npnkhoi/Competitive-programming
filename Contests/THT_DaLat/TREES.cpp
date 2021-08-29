#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "TREES"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e3 + 5;
const int C = 1e6 + 5;
const int maxC = 1e6;
int n, mx, mark[N];
vector<ii> edge[C];
vector<int> adj[N];
bool flag;

void dfs(int u) {
    REP(j, (int) adj[u].size()) {
        int v = adj[u][j];
        if (!mark[v]) {
            mark[v] = - mark[u];
            dfs(v);
        } else if (mark[v] == mark[u]) flag = 0;
    }
}
bool ok(int x) {
    FOR(i, 1, n) adj[i].clear();
    FOR(i, x+1, maxC) REP(j, (int) edge[i].size()) {
        adj[edge[i][j].fi].pb(edge[i][j].se);
        adj[edge[i][j].se].pb(edge[i][j].fi);
    }
    memset(mark, 0, sizeof mark);
    flag = 1;
    FOR(i, 1, n) if (mark[i] == 0) {
        mark[i] = 1;
        dfs(i);
    }
    return flag;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n-1) FOR(j, i+1, n) {
        int c;
        scanf("%d", &c);
        mx = max(mx, c);
        edge[c].push_back(mp(i, j));
    }
    int l = 0, r = 1e6, res = r;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (ok(mid)) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    printf("%d", res);
}
