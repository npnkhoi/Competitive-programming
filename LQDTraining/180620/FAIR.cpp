#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "FAIR"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e3 + 5;
const int V = 1e6 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int m, n, cc;
int a[N][N], id[N][N], vis[V], d[V];
vi adj[V];
queue<int> q;
void dfs(int i, int j, int _id) {
    id[i][j] = _id;
    REP(z, 4) {
        int u = i + dx[z], v =  j + dy[z];
        if (1 <= u && u <= m && 1 <= v && v <= n && !id[u][v] && a[u][v] == a[i][j])
            dfs(u, v, _id);
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) scanf("%d", &a[i][j]);
    FOR(i, 1, m) FOR(j, 1, n) if (id[i][j] == 0) {
        cc ++;
        dfs(i, j, cc);
    }
    FOR(i, 1, m) {
        adj[0].pb(id[i][1]);
        adj[id[i][1]].pb(0);
    }
    FOR(i, 1, m) {
        adj[cc+1].pb(id[i][n]);
        adj[id[i][n]].pb(cc+1);
    }
    FOR(i, 1, m) FOR(j, 1, n) {
        REP(z, 4) {
            int u = i + dx[z], v = j + dy[z];
            if (1 <= u && u <= m && 1 <= v && v <= n && id[u][v] != id[i][j]) {
                adj[id[i][j]].pb(id[u][v]);
                adj[id[u][v]].pb(id[i][j]);
            }
        }
    }
    memset(vis, 0, sizeof vis);
    q.push(0); vis[0] = 1;
    /*FOR(i, 1, m) {
        FOR(j, 1, n) cerr << id[i][j] << " ";
        cerr << "\n";
    }*/
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(j, adj[u].size()) {
            int v = adj[u][j];
            if (!vis[v]) {
                d[v] = d[u] + 1;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    printf("%d", d[cc+1] - 1);
}
