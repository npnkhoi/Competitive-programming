using namespace std;
#include <bits/stdc++.h>
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
const int N = 1e5 + 5;
const int oo = 1e9 + 7;
vector<int> adj[N];
int a[N];
bool mark[N];
int tmp;

void dfs(int u) {
    mark[u] = 1;
    tmp = min(tmp, a[u]);
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (mark[v] == 0) dfs(v);
    }
}
int main() {
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll res = 0;
    FOR(i, 1, n) if (mark[i] == 0) {
        tmp = oo;
        dfs(i);
        res += tmp;
    }
    printf("%lld\n", res);

    return 0;
}
/** Happy Coding :D */
