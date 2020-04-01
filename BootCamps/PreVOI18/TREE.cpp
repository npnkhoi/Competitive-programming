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
#define task "tree"

const int N = 5005;
const int oo = 1e9 + 7;

int n, res = oo;
int dp[N][N], a[N];
bool mark[N];
vector<int> child[N], adj[N];

void init(int u) {
    mark[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (mark[v] == 0) {
            child[u].pb(v);
            init(v);
        }
    }
}
void dfs(int u) {
    REP(j, child[u].size()) {
        int v = child[u][j];
        dfs(v);
    }
    if (child[u].size() == 0) {
        FOR(j, 2, n) dp[u][j] = oo;
        dp[u][0] = a[u];
        dp[u][1] = abs(a[u] - 1);
    } else if (child[u].size() == 1) {
        int v = child[u].back();
        FOR(j, 0, n) dp[u][j] = abs(a[u] - j) + dp[v][j];
    } else {
        int v = child[u][0];
        int t = child[u][1];
        FOR(j, 0, n) {
            dp[u][j] = oo;
            FOR(k, 0, j) dp[u][j] = min(dp[u][j], abs(a[u] - j) + dp[v][k] + dp[t][j-k]);
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    REP(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    init(1);
    dfs(1);
    FOR(i, 0, n) res = min(res, dp[1][i]);
    printf("%d", res);
    return 0;
}
/** Happy Coding :D */
