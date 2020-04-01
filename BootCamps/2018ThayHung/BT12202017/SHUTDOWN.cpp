#include <cstdio>
#include <utility>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define task "shutdown"
const int N = 505;
const int V = N*N;
const int LOG = 20;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int m, n, k, nVTX;
int a[N][N], anc[V][LOG + 5], dep[V];
int lab[V], minVtx[V];
bool mark[V];
pair<int, int> pos[V];
vector<int> adj[V];
queue<int> q;

int root(int u) {
    if (lab[u] < 0) return u;
    else return lab[u] = root(lab[u]);
}
void join(int u, int v) {
    u = root(u), v = root(v);
    if (lab[u] < lab[v]) {
        lab[v] = u;
    } else {
        lab[v] -= lab[u] == lab[v];
        lab[u] = v;
    }
}
bool inside(int x, int y) {
    return 1 <= x && x <= m && 1 <= y && y <= n;
}
void dfs(int u) {
    mark[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (mark[v] == 0) {
            anc[v][0] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    }
}
void bfs() {
    q.push(1); dep[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (dep[v] == 0) {
                anc[v][0] = u;
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
}
void initLCA() {
    for (int i = 1; (1 << i) <= nVTX; i++)
    for (int u = 1; u <= nVTX; u++)
        if ((1 << i) <= dep[u]) {
            anc[u][i] = anc[anc[u][i-1]][i-1];
        }
}
int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int tmp = dep[v] - dep[u];
    for (int i = 0; i <= LOG; i++) {
        if (((1 << i) & tmp) > 0) v = anc[v][i];
    }
    if (u == v) return u;
    for (int i = LOG; i >= 0; i--)
    if ((1 << i) <= dep[u] && anc[u][i] != anc[v][i])
        u = anc[u][i], v = anc[v][i];
    return anc[u][0];
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d%d", &m, &n, &k);
    nVTX = m*n;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; ++j) {
        scanf("%d", &a[i][j]);
        pos[a[i][j]] = make_pair(i, j);
    }
    memset(lab, -1, sizeof lab);

    for (int love = nVTX; love >= 1; love --) {
        int x = pos[love].first, y = pos[love].second;
        for (int z = 0; z < 4; z++) {
            int u = x + dx[z], v = y + dy[z];
            if (inside(u, v) && a[u][v] > a[x][y]
            && root(a[x][y]) != root(a[u][v])) {
                //printf("%d %d - %d %d\n", x, y, u, v);
                adj[a[x][y]].push_back(minVtx[root(a[u][v])]);
                //cerr << a[x][y] << " -> " << minVtx[root(a[u][v])] << "\n";
                join(a[x][y], a[u][v]);
            }
        }
        minVtx[root(a[x][y])] = a[x][y];
        //for (int i = 1; i <= n*n; i++) cerr << root(i) << " "; cerr << "\n";
    }
    dep[1] = 1;
    //dfs(1);
    bfs();
    initLCA();
    while (k--) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", LCA(u, v));
    }
    //cerr << LCA(15, 11);
}
