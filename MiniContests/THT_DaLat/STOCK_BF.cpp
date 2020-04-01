
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "stock"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 250;
int n, t, res;
bool mark[N];
vector<int> adj[N];

void dfs(int u) {
    mark[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!mark[v]) dfs(v);
    }
}
bool check(int u, int v) {
    memset(mark, 0, sizeof mark);
    dfs(u);
    return mark[v];
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d%d", &n, &t);
    REP(z, t) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (check(u, v)) res ++;
        else adj[v].push_back(u);
    }
    printf("%d", res);
}
