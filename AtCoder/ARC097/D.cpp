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

const int N = 1e5 + 5;
int lab[N], f[N], g[N];
int n, m, idx, res;
vector<int> adj[N];
void dfs(int u) {
    f[u] = idx; g[lab[u]] = idx;
    REP(j, (int) adj[u].size()) {
        int v = adj[u][j];
        if (!f[v]) dfs(v);
    }
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &lab[i]);
    FOR(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i, 1, n) if (!f[i]) {
        idx ++;
        dfs(i);
    }
    FOR(i, 1, n) res += (f[i] == g[i]);
    printf("%d", res);
}
