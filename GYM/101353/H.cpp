using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i,n) for (int i = 0; i < n; ++i)

const int N = 1e2 + 10;
const ll md = 1e9 + 7;

int n;
vector<ii> adj[N];
ll d[N];


void dfs(int u, ll h) {
    d[u] = h;
    REP(j, adj[u].size()) {
        ii v = adj[u][j];
        if (d[v.fi] == -1)
            dfs(v.fi, h+v.se);
    }
}
int main() {
    freopen("H.inp","r",stdin);
    freopen("H.out","w",stdout);
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        //printf("Case %d: ", tc);
        for (int i = 1; i <= n; i++) adj[i].clear();

        scanf("%d", &n);
        FOR(i, 1, n-1) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            adj[u].push_back(mp(v, c));
            adj[v].push_back(mp(u, c));
        }

        ll res = 0;
        FOR(i, 1, n) {
            memset(d, -1, sizeof d);
            dfs(i, 0);
            FOR(j, i+1, n) res = (res + d[j]) % md;
        }
        printf("%lld\n", res);
    }
    return 0;
}
/**/


