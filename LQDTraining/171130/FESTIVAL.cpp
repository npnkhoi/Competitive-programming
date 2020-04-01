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

#define taskName "festival"

const int N = 1e5 + 5;
int n, q, root;
vector<ii> adj[N];
bool mark[N];
ll dep[N];


void dfs(int u, ll d) {
    mark[u] = 1;
    dep[u] = d;
    REP(j, adj[u].size()) {
        ii v = adj[u][j];
        if (mark[v.fi] == 0) dfs(v.fi, d + v.se);
    }
}

int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".out", "w", stdout);
    scanf("%d", &n);
    REP(z, n-1) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
    }
    scanf("%d%d", &q, &root);
    dfs(root, 0);
    while (q --) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%lld\n", dep[u] + dep[v]);
    }
    return 0;
}
/** Happy Coding :D */
