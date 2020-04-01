#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

void dfs(int u, int par) {
    f[u][1][1] = d[i];
    f[u][0][0] = 0;
    if (par != -1) {
        FOR(j, 1, n) f[par][j][0] = min(f[par][j][0], f[par][j-1][0] + c[u]);
    }
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (v != par) dfs(v, u);
    }
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &b);
    FOR(i, 1, n) {
        scanf("%d%d", &c[i], &d[i]);
        d[i] = c[i] - d[i];
        if (i > 1) {
            int j;
            scanf("%d", &j);
            adj[i].pb(j);
        }
    }
    FOR(i, 1, n) FOR(j, 1, n) FOR(x, 0, 1) f[i][j][x] = oo;
    dfs(1, -1);
}
