#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "LMAZE"

const int N = 1e6 + 5;
vector<int> adj[N];
int mark[N];
int n;

void dfs(int u, int d) {
    mark[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (mark[v] == 0) dfs(v, d+1);
        else if (mark[v] == 1) {
            if (mark[n] == 1) printf("%d", 2*d - 3);
            else printf("-1");
            exit(0);
        }
    }
    mark[u] = 2;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        int x;
        scanf("%d", &x);
        adj[x].pb(i);
    }
    dfs(1, 1);
    printf("-1");
}
/** Happy Coding :D */
