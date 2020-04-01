#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define taskName ""

const int N = 1e4 + 1;
const int M = 1e5 + 5;
const int oo = 1e9 + 7;
int n, m, s, t, par[N];
long long flow;
int c[N][N], f[N][N];
vector<int> adj[N];
queue<int> q;
pair<ii, int> e[M];

bool findPath() {
    while (!q.empty()) q.pop(); q.push(s);
    memset(par, -1, sizeof par);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(j, adj[u].size()) {
            int v = adj[u][j];
            if (f[u][v] < c[u][v] && par[v] == -1) {
                par[v] = u;
                q.push(v);
                if (v == t) return true;
            }
        }
    }
    return false;
}
void incFlow() {
    int v = t;
    int delta = oo;
    do {
        delta = min(delta, c[par[v]][v] - f[par[v]][v]);
        v = par[v];
    } while (v != s);
    flow += delta;
    v = t;
    do {
        f[par[v]][v] += delta;
        f[v][par[v]] -= delta;
        v = par[v];
    } while (v != s);
}
int main() {
    freopen("FLOW.inp", "r", stdin);
    freopen("FLOW.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    REP(z, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
//        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] += w;
        e[z] = mp(mp(u, v), w);
    }

    while (1) {
        if (!findPath()) break;
        else incFlow();
    }
    printf("%lld\n", flow);
    REP(i, m) {
        int u = e[i].fi.fi;
        int v = e[i].fi.se;
        int val = min(f[u][v], e[i].se);
        f[u][v] -= val;
        if (val > 0) printf("%d\n", val);
        else printf("0\n");

    }
}
