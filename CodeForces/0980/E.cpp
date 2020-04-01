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

const int N = 1e6 + 5;
const int LOG = 25;
vi adj[N];
int n, k, cnt;
int anc[N][LOG], dep[N];
bool mark[N];

void dfs(int u) {
    REP(j, (int) adj[u].size()) {
        int v = adj[u][j];
        if (v != anc[u][0]) {
            anc[v][0] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    }
}
void calcAnc() {
    FOR(i, 1, 20) {
        FOR(u, 1, n) if ((1 << i) <= dep[u])
            anc[u][i] = anc[anc[u][i-1]][i-1];
    }
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(n);
    //FOR(i, 1, n) cerr << dep[i] << " "; cerr << "\n";
    calcAnc();
    mark[n] = 1; cnt = 1;
    for (int u = n-1; u >= 1 && cnt < n-k; u--) if (mark[u] == 0) {
        int v = u;
        FORD(d, 20, 0)
            if ((1 << d) <= dep[v] && mark[anc[v][d]] == 0)
                v = anc[v][d];
        v = anc[v][0];
        //cerr << u << " -> " << v << "\n";
        //cerr << dep[u] << " -> " << dep[v] << "\n";
        if (cnt + dep[u] - dep[v] <= n - k) {
            //cerr << "choose" << u << "\n";
            cnt += dep[u] - dep[v];
            //cerr << cnt << "\n";
            int t = u;
            while (t != v) {
                mark[t] = 1;
                t = anc[t][0];
            }
        }
    }
    //cerr << "ok\n";
    FOR(i, 1, n) if (!mark[i]) printf("%d ", i);
}
