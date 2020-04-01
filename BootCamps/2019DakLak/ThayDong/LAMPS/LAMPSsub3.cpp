#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "LAMPS"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 3005;
int color[N], tmp[N], n, tc;
vi adj[N];
bool dp[N][2][2];
vi saveDp[N][2][2], saveG[N][2][2][2];

void change(int u) {
    tmp[u] ^= 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        tmp[v] ^= 1;
    }
}
void show(vi &v) {
    printf("%d", v.size());
    REP(j, v.size()) printf(" %d", v[j]);
    printf("\n");
}
void concat(vi &a, vi& b) {
    //cerr << "concat size " << a.size() << " " << b.size() << "\n";
    REP(j, b.size()) a.pb(b[j]);
}
void dfs(int u, int par) {
    //cerr << "dfs " << u << "\n";
    int nChi = (int) adj[u].size() - (u != 1);
    int g[2][2][2];
    memset(g, 0, sizeof g);
    g[0][0][0] = g[0][0][1] = 1;
    int cur = 0, pre = 1;

    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (v != par) {
            dfs(v, u);
            cur ^= 1; pre ^= 1;
            //cerr << u << " -> " << v << "\n";
            REP(cntSon, 2) REP(chanPar, 2) {
                g[cur][cntSon][chanPar] = 0;
                if (g[pre][cntSon ^ 1][chanPar] & dp[v][1][chanPar ^ 1]) {
                    concat(saveG[u][cur][cntSon][chanPar], saveG[u][pre][cntSon ^ 1][chanPar]),
                    concat(saveG[u][cur][cntSon][chanPar], saveDp[v][1][chanPar ^ 1]),
                    g[cur][cntSon][chanPar] = 1;
                } else if (g[pre][cntSon][chanPar] & dp[v][0][chanPar ^ 1]) {
                    concat(saveG[u][cur][cntSon][chanPar], saveG[u][pre][cntSon][chanPar]),
                    concat(saveG[u][cur][cntSon][chanPar], saveDp[v][0][chanPar ^ 1]),
                    g[cur][cntSon][chanPar] = 1;
                }
            }
        }
    }
    //cerr << "result in vtx " << u << "\n";
    REP(chanPar, 2) REP(col, 2) {
        dp[u][chanPar][col] = g[cur][col ^ color [u] ^ chanPar][chanPar];
        if (dp[u][chanPar][col]) {
            saveDp[u][chanPar][col] = saveG[u][cur][col ^ color [u] ^ chanPar][chanPar];
            //show(saveDp[u][chanPar][col]);
            if (chanPar) saveDp[u][chanPar][col].pb(u);
            /*cerr << "dp " << u << " " << chanPar << " " << col << "\n";
            show(saveDp[u][chanPar][col]);
            cerr << "g " << (col ^ color [u] ^ chanPar) << " " << chanPar << "\n";*/
        }
        /*cerr << "g " << chanPar << " " << col << " = "
            << (int) g[cur][chanPar][col] << "\n";*/
        /*cerr << "dp " << u << " " << chanPar << " " << col << " = "
            << (int) dp[u][chanPar][col] << "\n";*/
    }
    //cerr << "------\n";
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &tc);
    FOR(z, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    while (tc --) {
        FOR(i, 1, n) scanf("%d", &color[i]);
        FOR(i, 1, n) REP(x, 2) REP(y, 2) {
            saveDp[i][x][y].clear();
            saveG[i][1][x][y].clear();
            saveG[i][0][x][y].clear();
        }
        memset(dp, 0, sizeof dp);
        dfs(1, -1);
        if (dp[1][0][1]) show(saveDp[1][0][1]);
        else if (dp[1][1][1]) show(saveDp[1][1][1]);
        else printf("-1\n");
    }
}
