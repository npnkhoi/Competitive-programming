#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)

#define taskname "bubbletea"

const int N = 5e4;
const int LOG = 20;
vector<ii> adj[N];

int n, k, khue;
int anc[N][LOG], dep[N], tmp[N], funID[N];
long long sumEdge[N][LOG];
bool mark[N];

void dfs(int u) {
    mark[u] = 1;
    REP(j, adj[u].size()) {
        ii v = adj[u][j];
        if (!mark[v.fi]) {
            anc[v.fi][0] = u;
            sumEdge[v.fi][0] = v.se;
            dep[v.fi] = dep[u] + 1;
            dfs(v.fi);
        }
    }
}
void initLCA() {
    for (int i = 1; (1 << i) <= n; i++) {
        FOR(u, 1, n) if ((1 << i) <= dep[u]) {
            anc[u][i] = anc[anc[u][i-1]][i-1];
            sumEdge[u][i] = sumEdge[u][i-1] + sumEdge[anc[u][i-1]][i-1];
        }
    }
}
long long dist(int u, int v) {
    long long res = 0;
    if (dep[u] > dep[v]) swap(u, v);
    while (dep[v] > dep[u]) {
        int x = (int)floor(log2(dep[v] - dep[u]));
        res += sumEdge[v][x];
        v = anc[v][x];
    }
    if (u == v) return res;
    FORD(i, LOG, 0) if ((1 << i) <= dep[u] && anc[u][i] != anc[v][i]) {
        res += sumEdge[u][i] + sumEdge[v][i];
        u = anc[u][i];
        v = anc[v][i];
    }
    res += sumEdge[u][0] + sumEdge[v][0];
    return res;
}
void sub1() {
    long long res = (long long)1e18;
    FOR(i, 1, k) tmp[i] = i;
    do {
        long long maxDist = 0;
        FOR(i, 1, k/2) maxDist = max(maxDist, dist(funID[tmp[2*i - 1]], funID[tmp[2*i]]));
        res = min(res, maxDist);
    } while (next_permutation(tmp + 1, tmp + k + 1));
    printf("%lld", res);
}
void sub2() {
    printf("%d", khue);
}
void sub3() {
    printf("%d", khue);
}
int main() {
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i, 1, k) scanf("%d", &funID[i]);
    FOR(i, 1, n) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
        khue = max(khue, c);
    }
    dep[1] = 1;
    dfs(1);
    initLCA();

    if (k <= 10) sub1();
    else if (k == n) sub2();
    else sub3();

}
