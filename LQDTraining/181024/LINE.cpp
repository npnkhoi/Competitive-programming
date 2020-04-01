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
#define task "LINE"

const int N = 1e3 + 5;
int cnt, nx, ny, m, res;
int matchx[N], matchy[N], trace[N];
vector<int> adj[N];
queue<int> q;
set<int> coorL, coorR;

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
    scanf("%d", &m);
    nx = ny = 500;
    REP(i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        coorL.insert(x);
        coorR.insert(y);
        adj[x].pb(y);
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
    if (res == max(coorL.size(), coorR.size())) printf("Slavko");
    else printf("Mirko");
    return 0;
}
/** Happy Coding :D */
