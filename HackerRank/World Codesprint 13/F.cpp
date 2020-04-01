#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "F"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5;
vi adj[N];
int cnt[N], par[N], dep[N], deg[N], head[N], num[N];
int IT[4*N];
int n, q, idx;

void precalc(int u) {
    cnt[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (cnt[v] == 0) {
            par[v] = u;
            dep[v] = dep[u] + 1;
            precalc(v);
            cnt[u] += cnt[v];
        }
    }
}
void hld(int u) {
    int w = -1;
    num[u] = ++ idx;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (v != par[u] && (w == -1 || cnt[w] < cnt[v])) w = v;
    }
    if (w == -1) return;
    head[w] = head[u];
    deg[w] = deg[u];
    hld(w);

    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (v != par[u] && v != w) {
            head[v] = v;
            deg[v] = deg[u] + 1;
            hld(v);
        }
    }
}
int lca(int u, int v) {
    while (deg[u] > deg[v]) u = par[head[u]];
    while (deg[u] < deg[v]) v = par[head[v]];
    while (head[u] != head[v])
        u = par[head[u]], v = par[head[v]];
    if (dep[u] < dep[v]) return u;
    else return v;
}
void update(int p, int l, int r, int idx, int val) {
    //cerr << "update " << l << " " << r << " " << idx << "\n";
    if (idx < l || r < idx) return;
    IT[p] += val;
    if (l < r) {
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*p, l, mid, idx, val);
        else update(2*p+1, mid+1, r, idx, val);
    }

}
int get(int p, int l, int r, int L, int R) {
    if (l > r || L > R || l > R || L > r) return 0;
    if (L <= l && r <= R) return IT[p];
    else {
        int mid = (l + r) / 2;
        return get(2*p, l, mid, L, R) + get(2*p+1, mid+1, r, L, R);
    }
}
int getpath(int u, int v) {
    //cerr << "get path " << u << " " << v << "\n";
    int res = 0;
    while (1) {
        if (head[u] == head[v]) {
            if (u != v) res += get(1, 1, n, num[u] + 1, num[v]);
            break;
        } else {
            res += get(1, 1, n, num[head[v]], num[v]);
            v = par[head[v]];
        }
    }
    //cerr << res << "\n";
    return res;
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d", &n);
    REP(z, n-1) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    precalc(1);
    head[1] = 1; hld(1);
    //FOR(i, 1, n) cerr << num[i] << " "; cerr << "\n";
    //FOR(i, 1, n) cerr << head[i] << " "; cerr << "\n";

    scanf("%d", &q);
    while (q --) {
        char cmd;
        int u, v;
        scanf(" %c%d%d", &cmd, &u, &v);
        if (v == par[u]) swap(u, v);
        //cerr << cmd << " " << u << " " << v << '\n';
        //cerr << num[u] << ' ' << num[v] << '\n';
        if (cmd == 'd') {
            if (u == par[v] && get(1, 1, n, num[v], num[v]) == 0) update(1, 1, n, num[v], 1);
        }
        else if (cmd == 'c') {
            if (u == par[v] && get(1, 1, n, num[v], num[v]) == 1) update(1, 1, n, num[v], -1);
        }
        else {
            int t = lca(u, v);
            //cerr << "ok lca\n";
            if (getpath(t, u) + getpath(t, v) == 0)
                printf("%d\n", dep[u] + dep[v] - 2 * dep[t]);
            else printf("Impossible\n");
        }
        //FOR(i, 1, n) cerr << get(1, 1, n, num[i], num[i]) << " "; cerr << "\n";
        //cerr << "ok\n";
    }
}
