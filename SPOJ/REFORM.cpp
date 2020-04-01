using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e5 + 10;
const int M = 2e5 + 10;
int n, m, idx, cc;
ll res, cnt[3], total;
vector<int> adj[N];
int num[N], low[N], par[N], nChild[N];
ii e[M];
void dfs(int u) {
    num[u] = low[u] = ++idx;
    cnt[cc] ++;
    nChild[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (num[v] == 0) {
            par[v] = u;
            dfs(v);
            nChild[u] += nChild[v];
            low[u] = min(low[u], low[v]);
        }
        else if (v != par[u]) low[u] = min(low[u], num[v]);
    }
}
void sub1() {
    //cerr << "sub1\n";
    int x = 0, y = 0;
    FOR(i, 1, m) {
        int u = e[i].fi, v = e[i].se;
        if (num[u] > num[v]) swap(u, v);
        if (low[v] > num[u]) res += 1LL * nChild[v] * (n - nChild[v]) - 1LL;
        else res += total - m;
    }
    printf("%lld", res);
}
void sub2() {
    FOR(i, 1, m) {
        int u = e[i].fi, v = e[i].se;
        if (num[u] > num[v]) swap(u, v);
        if (low[v] <= num[u]) res += 1LL;
    }
    res = res * cnt[1] * cnt[2];
    printf("%lld", res);
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &n, &m);
    total = 1LL * n * (n-1) / 2;
    FOR(i, 1, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
        e[i] = mp(u, v);
    }
    FOR(u, 1, n) if (num[u] == 0) {
        if (cc == 2) {
            printf("0");
            return 0;
        }
        cc ++; idx = 0; dfs(u);
    }
    //FOR(i, 1, n) cerr << nChild[i] << "\n";
    if (cc == 1) sub1();
    else if (cc == 2) sub2();
    return 0;
}
/** Happy Coding ^^ */
