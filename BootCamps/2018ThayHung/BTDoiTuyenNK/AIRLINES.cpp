//#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
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

#define task "airlines"

const int N = 2e5 + 5;
struct pack{
    long long d;
    int vtx, type;
};
pack Pack(long long d, int vtx, int type) {
    pack tmp;
    tmp.d = d;
    tmp.vtx = vtx;
    tmp.type = type;
    return tmp;
}
struct edge{
    int vtx, type, ord;
};
edge Edge(int v, int t, int o) {
    edge tmp;
    tmp.vtx = v;
    tmp.type = t;
    tmp.ord = o;
    return tmp;
}
bool operator < (const pack &a, const pack &b) {
    return a.d > b.d;
}

vector<edge> adj[N];
int n, m, k, x, y;
priority_queue<pack> heap;
map<int, long long> dist[N];
map<int, edge> trace[N];

void tracing(int vtx, int type) {
    if (vtx != 1) {
        edge e = trace[vtx][type];
        tracing(e.vtx, e.type);
        printf("%d ", e.ord);
    }
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d%d%d%d", &n, &m, &k, &x, &y);
    FOR(i, 1, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(Edge(v, c, i));
        adj[v].push_back(Edge(u, c, i));
    }

    heap.push(Pack(0, 1, 0));
    dist[1][0] = 0;

    while (!heap.empty()) {
        long long d = heap.top().d;
        int u = heap.top().vtx;
        int t = heap.top().type;
        heap.pop();

        if (d > dist[u][t]) continue;
        REP(j, adj[u].size()) {
            edge v = adj[u][j];
            int change = x;
            if (t > 0 && t != v.type) change += y;
            if (dist[v.vtx].find(v.type) == dist[v.vtx].end() || dist[v.vtx][v.type] > d + change) {
                dist[v.vtx][v.type] = d + change;
                trace[v.vtx][v.type] = Edge(u, t, v.ord);
                heap.push(Pack(d + change, v.vtx, v.type));
            }
        }
    }
    long long res = (long long)1e18;
    int saveType;
    for (map<int, long long>::iterator it = dist[n].begin(); it != dist[n].end(); it++) {
        if (it -> second < res) {
            res = it -> second;
            saveType = it -> first;
        }
    }
    printf("%lld\n", res);
    tracing(n, saveType);
}
/// Expelliarmus !
