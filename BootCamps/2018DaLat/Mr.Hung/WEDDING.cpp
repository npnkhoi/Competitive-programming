using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 3e5 + 5;
bool vis[N], hasB[N];
vector<int> adj[N];
int fa[N], fb[N], h[N], dep[N], par[N];
int n, a, b;

void DFS(int u) {
    vis[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (vis[v] == 0) {
            dep[v] = dep[u] + 1;
            par[v] = u;
            DFS(v);
            hasB[u] |= hasB[v];
            if (hasB[v] == 0) h[u] = max(h[u], 1 + h[v]);
        }
    }
    fa[u] = dep[u] + h[u];
    fb[u] = dep[b] - dep[u] + h[u];
}

int main() {
    freopen("WEDDING.inp", "r", stdin);
    freopen("WEDDING.out", "w", stdout);
    scanf("%d", &n);
    REP(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    scanf("%d%d", &a, &b);

    hasB[b] = 1;

    DFS(a);

    int u = b;
    while (u != a) {
        fa[u] = max(fa[u], fa[par[u]]);
        fb[par[u]] = max(fb[par[u]], fb[u]);
        u = par[u];
    }
    u = b;
    int res = 0;
    while (u != a) {
        res = max(res, min(fb[u], fa[par[u]]));
        u = par[u];
    }

    /*FOR(u, 1, n) if (hasB[u] && u != a) res = max(res, min(fb[u], fa[par[u]]));
    FOR(i, 1, n) cerr << g[i] << " "; cout << endl;
    FOR(i, 1, n) cerr << h[i] << " "; cout << endl;
    FOR(i, 1, n) cerr << fa[i] << " "; cout << endl;
    FOR(i, 1, n) cerr << fb[i] << " "; cout << endl;*/
    printf("%d\n", res+1);

    return 0;
}
