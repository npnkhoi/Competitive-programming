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

const int N = 2e5 + 5;
const ll md = 1e9 + 7;
int n, m;
vi adj[N];
int a[N], cnt[N], subOdd[N], subEven[N], allOdd[N], allEven[N], par[N];
bool mark[N];
long long cf[N];
void dfs1(int u) {
    mark[u] = 1;
    subOdd[u] = 0; subEven[u] = cnt[u] = 1;
    cf[u] = n - 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!mark[v]) {
            par[v] = u;
            dfs1(v);
            subOdd[u] += subEven[v];
            subEven[u] += subOdd[v];
            cnt[u] += cnt[v];

            cf[u] = (cf[u] + 1LL * (subOdd[v] - subEven[v]) * (n - cnt[v]) % md) % md;
            //printf("%d -> %d: %lld (%d, %d, %d)\n", u, v, cf[u], subOdd[v], subEven[v], cnt[v]);
        }
    }

}
void dfs2(int u) {
    mark[u] = 1;
    if (par[u] == 0) {
        allOdd[u] = subOdd[u];
        allEven[u] = subEven[u];
    } else {
        allOdd[u] = allEven[par[u]];
        allEven[u] = allOdd[par[u]];
    }
    cf[u] = (cf[u] + 1LL * cnt[u] * ((allEven[u] - subEven[u]) - (allOdd[u] - subOdd[u])) % md) % md;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!mark[v]) {
            dfs2(v);
        }
    }
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
    }
    FOR(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1);
    //FOR(i, 1, n)
    //    printf("%d %d %d %d %d %lld\n", cnt[i], subOdd[i], subEven[i], allOdd[i], allEven[i], cf[i]);

    memset(mark, 0, sizeof mark);

    dfs2(1);
    //FOR(i, 1, n)
    //    printf("%d %d %d %d %d %lld\n", cnt[i], subOdd[i], subEven[i], allOdd[i], allEven[i], cf[i]);
    long long res = 0;
    FOR(i, 1, n) res = (res + cf[i] * a[i] % md + md * md) % md;
    printf("%lld", res);
}
