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

const int N_IN_TEST = 35;
int lab[N_IN_TEST], siz[N_IN_TEST];
int root(int u) {
    if (lab[u] == -1) return u;
    else {
        lab[u] = root(lab[u]);
        return lab[u];
    }
}
void join(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    if (siz[u] > siz[v]) {
        lab[v] = u;
        siz[u] += siz[v];
    } else {
        lab[u] = v;
        siz[v] += siz[u];
    }
}
long long Rand(long long l, long long r) {
    return l + (1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1LL * rand() * (RAND_MAX + 1) +
                1LL * rand() ) % (r-l+1);
}
void test() {
    srand(time(NULL));
    ofstream inp(task".inp");
    int n = Rand(1, 5);
    inp << n << " 1\n";
    memset(lab, -1, sizeof lab);
    REP(z, n-1) {
        int u, v;
        do u = Rand(1, n-1), v = Rand(u+1, n);
        while (root(u) == root(v));
        inp << u << " " << v << "\n";
        join(u, v);
    }
    REP(i, n) inp << Rand(0, 1) << " ";
    inp.close();
}

const int N = 3005;
int color[N], tmp[N], n, tc;
vi adj[N];
bool dp[N][2][2];
vi saveDp[N][2][2], saveG[N][2][2];

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
                if (g[pre][cntSon ^ 1][chanPar] & dp[v][1][chanPar ^ 1])
                    concat(saveG[u][cntSon][chanPar], saveDp[v][1][chanPar ^ 1]),
                    g[cur][cntSon][chanPar] = 1;
                else if (g[pre][cntSon][chanPar] & dp[v][0][chanPar ^ 1])
                    concat(saveG[u][cntSon][chanPar], saveDp[v][0][chanPar ^ 1]),
                    g[cur][cntSon][chanPar] = 1;
            }
        }
    }
    REP(chanPar, 2) REP(col, 2) {
        dp[u][chanPar][col] = g[cur][col ^ color [u] ^ chanPar][chanPar];
        if (dp[u][chanPar][col]) {
            //cerr << u << " " << chanPar << " " << col << "\n";
            saveDp[u][chanPar][col] = saveG[u][col ^ color [u] ^ chanPar][chanPar];
            //show(saveDp[u][chanPar][col]);
            if (chanPar) saveDp[u][chanPar][col].pb(u);
            //show(saveDp[u][chanPar][col]);
        }
        /*cerr << "g " << chanPar << " " << col << " = "
            << (int) g[cur][chanPar][col] << "\n";
        cerr << "dp " << u << " " << chanPar << " " << col << " = "
            << (int) dp[u][chanPar][col] << "\n";*/
    }
    //cerr << "------\n";
}
void subN() {
    dfs(1, -1);
    if (dp[1][0][1]) show(saveDp[1][0][1]);
    else if (dp[1][1][1]) show(saveDp[1][1][1]);
    else printf("-1\n");
}

void check() {
    int nVtx, u;
    freopen(task".out", "r", stdin);
    FOR(i, 1, n) tmp[i] = color[i];
    //FOR(i, 1, n) cerr << tmp[i] << " "; cerr << '\n';
    cin >> nVtx;
    //cerr << n << " " << nVtx << "\n";
    REP(i, nVtx) {
        cin >> u;
        change(u);
    }
    //FOR(i, 1, n) cerr << tmp[i] << " "; cerr << '\n';
    bool flag = 1;
    FOR(i, 1, n) if (tmp[i] == 0) {
        flag = 0;
        //cerr << "wrong at " << i << '\n';
    }
    //cerr << nVtx << "\n";
    if (flag || nVtx == -1) cerr << "CORRECT"; else {
        cerr << "WRONG-----------";
        exit(0);
    }
}

int main() {
   //while (1) { test();
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
            saveG[i][x][y].clear();
        }
        memset(dp, 0, sizeof dp);
        //cerr << "in sub N\n";
        subN();
    }
    //check();

    //REP(i, 1e8);
}
