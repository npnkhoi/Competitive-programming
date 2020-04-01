using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
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

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 1e5 + 5;
const ll oo  = 1e17 + 9;

struct pack {
    int u, v, h, d;
} e[N];
bool cmp(pack &a, pack &b) {
    return a.h > b.h;
}
vector<ii> adj[N];
vector<int> ans;
int root[N], Rank[N], pre[N];
ll dist[N];
priority_queue<li, vector<li>, greater<li> > pq;

int getRoot(int u) {
    return (u == root[u]) ? u : root[u] = getRoot(root[u]);
}
void join(int u, int v) {
    u = getRoot(u), v = getRoot(v);
    if (Rank[u] > Rank[v]) root[v] = u;
    else {
        root[u] = v;
        if (Rank[u] == Rank[v]) ++ Rank[v];
    }
}
int main() {
    freopen("HEIGHT.inp", "r", stdin);
    freopen("HEIGHT.out", "w", stdout);
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    REP(i, m) scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].h, &e[i].d);
    sort(e, e+m, cmp);
    //REP(i, m) printf("%d %d %d %d\n", e[i].u, e[i].v, e[i].h, e[i].d);
    //cerr << "\n";

    FOR(i, 1, n) root[i] = i;
    //cerr << "ok\n";

    for (int i = 0; i < m; ) {
        int j = i;
        for (; j < m && e[i].h == e[j].h; ++j) {
            //cerr << j << "\n";
            int u = e[j].u, v = e[j].v;
            //cerr << u << " " << v << "\n";
            if (getRoot(u) != getRoot(v)) join(u, v);
            adj[u].push_back(mp(v, e[j].d));
            adj[v].push_back(mp(u, e[j].d));
        }
        i = j;
        if (getRoot(s) == getRoot(t)) break;
    }

    FOR(i, 1, n) dist[i] = oo; dist[s] = 0;
    pq.push(mp(0, s));

    while (!pq.empty()) {
        ll d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (d > dist[u]) continue;
        //if (u == t) break;

        REP(j, adj[u].size()) {
            ii v = adj[u][j];
            if (dist[v.fi] > d + v.se) {
                dist[v.fi] = d + v.se;
                pq.push(mp(dist[v.fi], v.fi));
                pre[v.fi] = u;
            }
        }
    }
    /*cerr << "Graph\n";
    FOR(i, 1, n) {
        REP(j, adj[i].size()) printf("(%d, %d)", adj[i][j].fi, adj[i][j].se);
        cerr << "\n";
    }
    cerr << dist[t] << "\n";*/
    int x = t;
    ans.push_back(t);
    while (x != s) {
        ans.push_back(pre[x]);
        x = pre[x];
    }
    printf("%d\n", ans.size());
    FORD(i, ans.size() - 1, 0) printf("%d ", ans[i]);

    return 0;
}
/** Happy Coding :D */
