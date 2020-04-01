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

const int N = 1e5 + 5;
int color[N], tmp[N], n, tc;
vi adj[N];
void change(int u) {
    //cerr << "change " << u << "\n";
    tmp[u] ^= 1;
    //cerr << u < " ";
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        tmp[v] ^= 1;
        //cerr << v << " ";
    }
    //cerr << "\n";
}
void sub1() {
    /*int khue = 0;
    khue |= (1 << 1-1);
    khue |= (1 << 2-1);
    khue |= (1 << 4-1);
    khue |= (1 << 5-1);
    khue |= (1 << 8-1)*/
    REP(mask, (1 << n)) {
        FOR(i, 1, n) tmp[i] = color[i];
        REP(i, n) if ((mask & (1 << i)) > 0) {
            change(i+1);
            /*if (mask == khue) {
                cerr << "after change " << i + 1 << "\n";
                FOR(i, 1, n) cerr << tmp[i] << " "; cerr << "\n";
            }*/
        }
        bool flag = 1;
        FOR(i, 1, n) if (tmp[i] == 0) flag = 0;
        if (flag) {
            int res =  __builtin_popcount(mask), cnt = 0;
            printf("%d", res);
            REP(i, n) if ((mask & (1 << i)) > 0) {
                printf(" %d", i+1);
            }
            printf("\n");
            return;
        }
    }
    printf("-1\n");
}
/*void dfs(int u, int par) {
    int nChi = (int) adj[u].size() - (u != 1);
    int g[2][2];
    memset(g, 0, sizeof g);
    g[0][0] = 1;
    int cur = 0, pre = 1;

    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (v != par) {
            dfs(v);
            cur ^= 1; pre ^= 1;
            REP(cnt, 2) {
                g[cur][cnt] = (g[pre][cnt^1] & dp[i][1][change])
                | (g[pre][cnt] & dp[i][0][change^1]);
            }
        }
    }
}
void subN() {
    dfs(1, -1);
}*/
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &tc);
    FOR(z, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
        //cerr << u << " - " << v << "\n";
    }
    while (tc --) {
        FOR(i, 1, n) scanf("%d", &color[i]);
        if (n <= 20) sub1();
    }
}
