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
const int N = 5e3 + 5;
int n, m, s;
vi adj[N], topo;
int mark[N];

void topoSort(int u) {
    mark[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!mark[v]) topoSort(v);
    }
    topo.pb(u);
}
void dfs(int u) {
    mark[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!mark[v]) dfs(v);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n >> m >> s;
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    FOR(i, 1, n) if (!mark[i]) topoSort(i);
    reverse(topo.begin(), topo.end());
    memset(mark, 0, sizeof mark);
    dfs(s);
    int res = 0;
    REP(i, n)  {
        int v = topo[i];
        if (!mark[v]) res ++, dfs(v);
    }
    cout << res;
}
