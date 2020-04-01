#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 1e5 + 10;
vector<int> adj[N];
int ft[N], n, k;
bitset<N> sign;
long long res;
void adjust(int p, int v) {
    for (; p <= n; p += p&(-p)) ft[p] += v;
}
int rsq(int x) {
    int res = 0;
    for (; x; x -= x&(-x)) res += ft[x];
    return res;
}
int rsq(int l, int r) {
    return rsq(r) - rsq(l-1);
}
void pre(int u) {
    sign[u] = 1;
    REP(j, adj[u].size()) pre(adj[u][j]);
}
void dfs(int u) {
    res += 1LL * rsq(max(1, u-k), min(n, u+k));
    // cout << u << " " << res << endl;
    adjust(u, +1);
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        dfs(v);
    }
    adjust(u, -1);
}
int main() {
    freopen("PERFECT.inp", "r", stdin);
    freopen("PERFECT.out", "w", stdout);
    scanf("%d %d", &n, &k);
    REP(z, n-1) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    int root = 0;
    FOR(u, 1, n) if (sign[u] == 0) root = u, pre(u); /// find root
    //cout << root << endl;
    dfs(root);
    printf("%lld", res);
}
