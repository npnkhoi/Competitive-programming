#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "graph"
const int N = 2e5 + 5;
ii e[N];
vector<int> data;
vector<int> adj[N];
map<int, int> id;
bool mark[N];
int n, m, p, s, t;

void dfs(int u) {
    mark[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!mark[v]) dfs(v);
    }
}
bool ok(int m) {
    memset(mark, 0, sizeof mark);
    FOR(i, 1, p) adj[i].clear();
    FOR(i, 1, m) adj[e[i].fi].pb(e[i].se);
    dfs(s);
    return mark[t];
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d%d", &m, &s, &t);
    data.pb(s); data.pb(t);
    FOR(i, 1, m) {
        scanf("%d%d", &e[i].fi, &e[i].se);
        data.pb(e[i].fi);
        data.pb(e[i].se);
    }
        sort(data.begin(), data.end());
        p = 0;
        REP(i, data.size())
        if (i == 0 || data[i] != data[i-1]) id[data[i]] = ++p;
        FOR(i, 1, m) e[i].fi = id[e[i].fi], e[i].se = id[e[i].se];
        s = id[s], t = id[t];
    int l = 1, r = m, d = m;
    while (l <= r) {
        int mi = (l+r) / 2;
        if (ok(mi)) {
            d = min(d, mi);
            r = mi - 1;
        } else l = mi + 1;
    }
    //cerr << d << ok(4) << "\n";
    if (!ok(d)) printf("0");
    else printf("%d", d);
}
/** Happy Coding :D */
