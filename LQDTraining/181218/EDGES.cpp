#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "EDGES"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
const ll oo = 1e18;

int n, m, m2, idx, scc, s, t;
int onStack[N], num[N], low[N], id[N], degIn[N], degOut[N], mark[N];
ll dist[N];
vi adj[N], topo;
vector<ii> g[N];
stack<int> st;
priority_queue<li, vector<li>, greater<li> > q;

void input1() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> m;
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

void tarjan(int u) {
    //cerr << "dfs " << u << '\n';
    st.push(u);
    onStack[u] = 1;
    num[u] = low[u] = ++ idx;
    REP(i, adj[u].size()) {
        int v = adj[u][i];
        if (num[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (num[u] == low[u]) {
        scc ++;
        while (1) {
            int t = st.top();
            //cerr << t << " in " << scc << '\n';
            st.pop();
            onStack[t] = 0;
            id[t] = scc;
            if (t == u) break;
        }
    }
}

void compress() {
    FOR(i, 1, n) if (num[i] == 0) tarjan(i);
    if (scc == 1) {
        cout << "YES\n0";
        exit(0);
    }
}

void input2() {
    cin >> m2;
    REP(i, m2) {
        int u, v, c;
        cin >> u >> v >> c;
        if (id[u] != id[v]) {
            g[id[u]].push_back(mp(id[v], c));
            //cerr << id[u] << ' ' << id[v] << ' ' << c << '\n';
        }
    }
}

void dijkstra() {
    FOR(i, 1, scc) dist[i] = oo;
    dist[t] = 0;
    q.push(mp(0, t));
    while (!q.empty()) {
        li t = q.top();
        q.pop();

        if (t.fi != dist[t.se]) continue;

        REP(i, g[t.se].size()) {
            ii v = g[t.se][i];
            if (dist[v.fi] > dist[t.se] + v.se) {
                dist[v.fi] = dist[t.se] + v.se;
                q.push(mp(dist[v.fi], v.fi));
            }
        }
    }
}

void topoSort(int u) {
    mark[u] = 1;
    REP(i, g[u].size()) {
        int v = g[u][i].fi;
        if (!mark[v]) topoSort(v);
    }
    topo.push_back(u);
}

void minPath() {
    FOR(i, 1, scc) if (!mark[i]) topoSort(i);
    reverse(all(topo));
    FOR(i, 1, scc) dist[i] = oo;
    dist[topo[0]] = 0;
    REP(i, scc) {
        int u = topo[i];
        REP(j, g[u].size()) {
            ii v = g[u][j];
            dist[v.fi] = min(dist[v.fi], dist[u] + v.se);
        }
    }
}

void output() {
    if (dist[topo.back()] == oo) cout << "NO";
    else cout << "YES\n" << dist[topo.back()];
}

int main() {
	input1();
    compress();
    input2();
    minPath();
    output();
}

