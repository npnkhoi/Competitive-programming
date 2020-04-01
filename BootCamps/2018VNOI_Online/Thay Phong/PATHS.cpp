#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)
#define task "paths"
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
struct TEdge{
    int u, v, c;
};
const int N = 1500 + 5;
const int M = 5000 + 5;
const int oo = 1e9 + 7;
const int md = 1e9 + 7;
TEdge e[M];
vector<ii> adj[N];
int n, m, dist[N][N], cnt[N][N], f[N], g[N];
long long save[N][N];
bool mark[N][N];
priority_queue<ii, vector<ii>, greater<ii> > heap;
map<int, int> myMap;


void dijsktra(int s, int dist[], int cnt[]) {
    FOR(i, 1, n) dist[i] = oo; dist[s] = 0;
    cnt[s] = 1;
    while (!heap.empty()) heap.pop(); heap.push(mp(0, s));

    while (!heap.empty()) {
        int d = heap.top().fi;
        int u = heap.top().se;
        heap.pop();

        if (d > dist[u]) continue;

        REP(j, adj[u].size()) {
            ii v = adj[u][j];
            if (dist[v.fi] > d + v.se) {
                dist[v.fi] = d + v.se;
                cnt[v.fi] = cnt[u];
                heap.push(mp(dist[v.fi], v.fi));
            } else if (dist[v.fi] == d + v.se)
                cnt[v.fi] = (cnt[v.fi] + cnt[u]) % md;
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d %d", &n, &m);
    REP(i, m) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        e[i].u = u;
        e[i].v = v;
        e[i].c = c;
        adj[u].pb(mp(v, c));
        //adj[v].pb(mp(u, c));
    }
    FOR(i, 1, n) dijsktra(i, dist[i], cnt[i]);
    /*FOR(i, 1, n) {
        FOR(j, 1, n) printf("%10d", dist[i][j]);
        printf("\n");
    }
    FOR(i, 1, n) {
        FOR(j, 1, n) printf("%10d", cnt[i][j]);
        printf("\n");
    }*/
    REP(i, m) {
        //myMap.clear();
        int u = e[i].u;
        int v = e[i].v;
        int c = e[i].c;
        if (dist[u][v] < c) {
            printf("0\n");
            continue;
        }
        if (mark[u][v]) {
            printf("%d\n", save[u][v]);
            continue;
        }
        int p = 0, q = 0;
        FOR(x, 1, n) if (dist[x][u] + c == dist[x][v]) f[++p] = x;
        FOR(y, 1, n) if (c + dist[v][y] == dist[u][y]) g[++q] = y;

        long long res = 0;
        FOR(x, 1, p) FOR(y, 1, q)
        if (dist[f[x]][u] + c + dist[v][g[y]] == dist[f[x]][g[y]]) {
            res = (res + 1LL * cnt[f[x]][u] * cnt[v][g[y]]) % md;
            /*cerr << f[x] << " " <<  u << " " << v << " " << g[y] << " " <<
             1LL * cnt[f[x]][u] * cnt[v][g[y]] << "\n";*/
        }
        //myMap[mp(u, v)] = res;
        save[u][v] = res;
        mark[u][v] = 1;
        printf("%lld\n", res);
    }
}
