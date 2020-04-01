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
#define task "journey"
struct P { ll x, y; };
const int N = 1e3 + 5;
int nx, ny, m, res;
int matchx[N], matchy[N], trace[N];
vector<int> adj[N];
queue<int> q;
P a[N], b[N];
double dist(P &a, P &b) {
    return sqrt((double)(a.x - b.x) * (a.x - b.x) + (double)(a.y - b.y) * (a.y - b.y));
}
int findAugment() {
    while (!q.empty()) q.pop();
    memset(trace, 0, sizeof trace);
    FOR(i, 1, nx) if (matchx[i] == 0)
        q.push(i); /// push all un-matched vtx.es into queue
    /// BFS
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(j, adj[u].size()) {
            int v = adj[u][j];
            if (trace[v] == 0) {
                trace[v] = u;
                if (matchy[v] == 0) return v;
                else q.push(matchy[v]);
            }
        }
    }
    return 0;
}
void enLarge(int u) {
    res ++;
    while (1) {
        int v = matchx[trace[u]];
        matchx[trace[u]] = u;
        matchy[u] = trace[u];
        if (v == 0) break;
        else u = v;
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &nx, &ny);
    FOR(i, 0, nx) scanf("%lld%lld", &a[i].x, &a[i].y);
    FOR(j, 1, ny) scanf("%lld%lld", &b[j].x, &b[j].y);

    FOR(i, 1, nx) FOR(j, 1, ny) {
        //cerr << dist(b[i], a[i-1]) << " " << dist(b[i], a[i]) << " " << 2 * dist(a[i-1], a[i]) << "\n";
        if (dist(b[j], a[i-1]) + dist(b[j], a[i]) <= 2 * dist(a[i-1], a[i])) {
            adj[i].pb(j);
            //cerr << i << " " << j << "\n";
        }
    }
    ///pre matching
    FOR(u, 1, nx) REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!matchy[v]) {
            matchx[u] = v;
            matchy[v] = u;
            res ++;
            break;
        }
    }
    /// matching algorithm with augmenting path
    while (1) {
        int tmp = findAugment();
        if (tmp == 0) break;
        else enLarge(tmp);
    }
    printf("%d", res);
    return 0;
}
/** Happy Coding :D */

