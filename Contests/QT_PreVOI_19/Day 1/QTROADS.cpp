#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "QTROADS"

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5, LOG = 17, oo = 1e9 + 7;

int n, m, idx;
int dep[N], anc[N][LOG + 2], upEdge[N][LOG + 2], 
    ans[N], lab[N], son[N], id[N], cnt[N], num[N], head[N];
vi add[N], del[N];
vector<ii> adj[N];
multiset<int> data;
pair<ii, int> e[N];

void dfs(int u, int par) {
    for (int i = 1; (1 << i) <= dep[u]; ++i) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
        upEdge[u][i] = max(upEdge[u][i-1], upEdge[anc[u][i-1]][i-1]);
    }
    cnt[u] = 1;
    REP(i, adj[u].size()) {
        int v = adj[u][i].X;
        if (v == par) continue;

        dep[v] = dep[u] + 1;
        anc[v][0] = u;
        upEdge[v][0] = e[adj[u][i].Y].Y;

        dfs(v, u);

        cnt[u] += cnt[v];
    }
}

void hld(int u, int par) {
    num[u] = ++idx;

    int heavy = -1;
    REP(i, adj[u].size()) {
        int  v = adj[u][i].X;
        if (v == par) continue;
        if (heavy == -1 || cnt[v] > cnt[heavy]) {
            heavy = v;
            id[idx + 1] = adj[u][i].Y;
        }
    }

    son[u] = heavy;
    if (heavy == -1) return;

    head[heavy] = head[u];
    hld(heavy, u);

    REP(i, adj[u].size()) {
        int v = adj[u][i].X;
        if (v == par || v == heavy) continue;
        head[v] = v;
        id[idx + 1] = adj[u][i].Y;
        hld(v, u);
    }
}

void update(int u, int v, int val) {
    int ret = 0;
    while (head[u] != head[v]) {
        add[num[head[v]]].push_back(val);
        del[num[v]].push_back(val);
        v = anc[head[v]][0];
    }
    if (u == v) return;
    if (dep[u] > dep[v]) swap(u, v);
    add[num[son[u]]].push_back(val);
    del[num[v]].push_back(val);
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    FORD(i, LOG, 0)
        if (dep[v] - (1 << i) >= dep[u])
            v = anc[v][i];
    if (u == v) return u;
    FORD(i, LOG, 0) {
        if ((1 < i) <= dep[u] && anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}

int getMaxEdge(int u, int v) {
    int res = 0;
    FORD(i, LOG, 0) if (dep[v] - (1 << i) >= dep[u]) {
        res = max(res, upEdge[v][i]);
        v = anc[v][i];
    }
    return res;
}

int root(int u) {
    if (lab[u] < 0) return u;
    else return lab[u] = root(lab[u]);
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] -= (lab[u] == lab[v]);
    lab[v] = u;
}

void check() {
    int x, y;
    while (1) {
        x = x + y;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    check();
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> m;
    memset(lab, -1, sizeof lab);
    FOR(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        e[i] = mp(mp(u, v), c);
        if (i < n) {
            unite(u, v);
            adj[u].push_back(mp(v, i));
            adj[v].push_back(mp(u, i));
        }
    }

    dfs(1, -1);
    head[1] = 1;
    hld(1, -1);

    FOR(i, n, m) {
        int u = e[i].X.X, v = e[i].X.Y, t = lca(u, v);

        ans[i] = e[i].Y - max(getMaxEdge(t, u), getMaxEdge(t, v));

        update(t, u, e[i].Y);
        update(t, v, e[i].Y);
    }

    FOR(x, 1, n) {
        REP(i, add[x].size()) {
            data.insert(add[x][i]);
        }
        if (!data.empty()) ans[id[x]] = *data.begin() - e[id[x]].Y;
        else ans[id[x]] = -1;
        REP(i, del[x].size()) {
            data.erase(data.find(del[x][i]));
        }
    }
    lint res = 0;
    FOR(i, 1, m) {
        // cerr << ans[i] << '\n';
        lint x = ans[i], y = -1;
        if (i >= n) swap(x, y);
        res += i * x + y * i * i;
    }
    cout << res;
}
