using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e5 + 10;
int n, m, res = 0;
iii e[N];
vector<ii> adj[N];
int root[N], Rank[N];
int par[N], nChild[N];
int idx, head[N], num[N], dep[N];
int IT[4*N], a[N];
int getRoot(int u) {
    return (u == root[u]) ? u : root[u] = getRoot(root[u]);
}
void join(int u, int v) {
    u = getRoot(u); v = getRoot(v);
    if (Rank[u] > Rank[v]) {
        root[v] = u;
        //emax[u] = max(max(emax[u], emax[v]), c);
    }
    else {
        root[u] = v;
        //emax[v] = max(max(emax[v], emax[u]), c);
        if (Rank[u] == Rank[v]) Rank[v] ++;
    }
}
void init(int u) {
    nChild[u] = 0;
    REP(j, adj[u].size()) {
        int v = adj[u][j].fi;
        if (v != par[u]) {
            par[v] = u;
            init(v);
            nChild[u] += 1 + nChild[v];
        }
    }
}
void HLD(int u) {
    num[u] = ++idx;
    int super = -1, superE;
    REP(j, adj[u].size()) {
        int v = adj[u][j].fi;
        if (v != par[u] && (super == -1 || nChild[v] > nChild[super]))
            super = v, superE = adj[u][j].se;
    }
    if (super != -1) {
        head[super] = head[u];
        dep[super] = dep[u];
        a[idx+1] = superE;
        HLD(super);
    }
    REP(j, adj[u].size()) {
        int v = adj[u][j].fi;
        if (v != par[u] && v != super) {
            head[v] = v;
            dep[v] = dep[u] + 1;
            a[idx+1] = adj[u][j].se;
            HLD(v);
        }
    }
}
int LCA(int u, int v) {
    while (head[u] != head[v]) {
        if (dep[u] > dep[v]) u = par[head[u]];
        else v = par[head[v]];
    }
    return (num[u] < num[v]) ? u : v;
}
void build(int p, int l, int r) {
    if (l > r) return;
    if (l == r) IT[p] = a[l];
    else {
        int mi = (l+r)/2;
        build(2*p, l, mi);
        build(2*p+1, mi+1, r);
        IT[p] = max(IT[2*p], IT[2*p+1]);
    }
}
int RMQ(int p, int l, int r, int L, int R) {
    if (l > r || L > R || l > R || L > r) return -1;
    if (L <= l && r <= R) return IT[p];
    else {
        int mi = (l+r)/2;
        return max(RMQ(2*p, l, mi, L, R), RMQ(2*p+1, mi+1, r, L, R));
    }
}
int maxEdge(int u, int v) {
    int t = LCA(u, v), ans = -1;
    //printf("%d %d (lca %d): ", u, v, t);
    while (dep[u] > dep[t]) {
        ans = max(ans, RMQ(1, 1, n, num[head[u]], num[u]));
        u = par[head[u]];
    }
    ans = max(ans, RMQ(1, 1, n, num[t]+1, num[u]));

    while (dep[v] > dep[t]) {
        ans = max(ans, RMQ(1, 1, n, num[head[v]], num[v]));
        v = par[head[v]];
    }
    ans = max(ans, RMQ(1, 1, n, num[t]+1, num[v]));
    //cout << ans << endl;
    return ans;
}
int main() {
    freopen("bgame.inp","r",stdin);
    freopen("bgame.out","w",stdout);
    scanf("%d%d", &n, &m);
    REP(i, m) scanf("%d%d%d", &e[i].se.fi, &e[i].se.se, &e[i].fi);
    sort(e, e+m, greater<iii>());
    memset(Rank, 0, sizeof Rank);
    REP(i, n+2) root[i] = i;
    //---------------
    REP(i, m) {
        int u = e[i].se.fi, v = e[i].se.se, c = e[i].fi;
        if (getRoot(u) != getRoot(v)) {
            adj[u].pb(mp(v, c));
            adj[v].pb(mp(u, c));
            e[i].fi = -1; /// delete edge
            join(u, v);
            //cout << u << " " << v << endl;
            //FOR(i, 1, n) cout << getRoot(i) << " "; cout << endl;
        }
    }
    FOR(i, 1, n) if (i == getRoot(i))
        adj[0].push_back(mp(i, 0));
    /*REP(u, n+1) {
        REP(j, adj[u].size()) cout << adj[u][j].fi << " ";
        cout << endl;
    }*/
    //-------------------
    idx = -1;
    init(0);
    HLD(0);
    //REP(i, n+1) cout << num[i] << " "; cout << endl;
    //REP(i, n) cout << a[i+1] << " "; cout << endl;
    build(1, 1, n);
    //--------------------
    REP(i, m) if (e[i].fi != -1)
        res = max(res, e[i].fi + maxEdge(e[i].se.fi, e[i].se.se));
    printf("%d", res);
    return 0;
}
/** Happy Coding ^^ */
