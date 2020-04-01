using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
const int N = 2e3 + 5;
const int sh = 1000;
const int maxCoor = 2000;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n;
bool adj[N][N][4], vis[N][N];

int deg(int x, int y) {
    int res = 0;
    REP(z, 4) res += adj[x][y][z];
    return res;
}
int main() {
    freopen("ARCHI.inp", "r", stdin);
    freopen("ARCHI.out", "w", stdout);

    scanf("%d", &n);
    FOR(i, 1, n) {
        int x, y, u, v;
        scanf("%d%d%d%d", &x, &y, &u, &v);
        x += sh;
        y += sh;
        u += sh;
        v += sh;

        if (y == v) {
            if (x > u) swap(x, u);
            adj[x][y][3] = 1;
            adj[u][v][1] = 1;
            FOR(j, x+1, u-1)
                adj[j][y][1] = adj[j][v][3] = 1;
        } else {
            if (y > v) swap(y, v);
            adj[x][y][0] = 1;
            adj[u][v][2] = 1;
            FOR(j, y+1, v-1)
                adj[x][j][0] = adj[v][j][2] = 1;
        }
    }
    memset(vis, 0, sizeof vis);
    int res = 0;

    FOR(i, 0, maxCoor) FOR(j, 0, maxCoor)
    if (vis[i][j] == 0 && deg(i, j) > 0) {
        queue<ii> q;
        q.push(mp(i, j));
        vis[i][j] = 1;

        int cnt = deg(i, j) % 2;
        while (!q.empty()) {
            ii t = q.front(); q.pop();
            FOR(z, 0, 3) if (adj[t.fi][t.se][z]) {
                int u = t.fi + dx[z];
                int v = t.se + dy[z];
                if (vis[u][v] == 0) {
                    vis[u][v] = 1;
                    q.push(mp(u, v));
                    cnt += deg(u, v) % 2;
                    //cerr << u << " " << v << "\n";
                }
            }
        }
        if (cnt == 0) res += 1;
        else res += cnt/2;
    }
    printf("%d\n", res);
}
