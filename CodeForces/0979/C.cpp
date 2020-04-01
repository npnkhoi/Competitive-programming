#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task "BULMART"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 3e5 + 5;
vi adj[N];
int n, x, y;
int wei[N], hasY[N];

void dfs(int u, int par) {
    wei[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (v != par) {
            dfs(v, u);
            wei[u] += wei[v];
            hasY[u] |= hasY[v];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n >> x >> y;
    hasY[y] = 1;
    REP(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(x, -1);
    int cntX = 1, cntY = wei[y];
    REP(j, adj[x].size()) {
        int u = adj[x][j];
        if (!hasY[u]) cntX += wei[u];
    }
    //cerr << cntX << " " << cntY << "\n";
    cout << 1LL * n * (n-1) - 1LL * cntX * cntY;
}
