#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 7;
const int K = 1000 + 5;
int k, n, a, b, c, u, v, t;
int dist[N][N][N], res, e[K][8];
struct state { int x, y, z;
    state (int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};
bool ok(state g) {
    return g.x >= u && g.y >= v && g.z >= t && g.x <= 4 && g.y <= 4 && g.z <= 4;
}
int main() {
    //freopen("0.in", "r", stdin);
    scanf("%d", &k);
    scanf("%d %d %d %d %d %d", &a, &b, &c, &u, &v, &t);
    n = -1;
    while (scanf("%d", &e[++n][0]) != EOF) {
        FOR(i, 1, 5) scanf("%d", &e[n][i]);
        e[n][3] -= e[n][0];
        e[n][4] -= e[n][1];
        e[n][5] -= e[n][2];
        //REP(i, 6) printf("%d ", e[n][i]);
        //cout << endl;
    }
    n++;
    queue<state> q;
    q.push(state(a, b, c)); dist[a][b][c] = 0;

    while (!q.empty()) {
        state tmp = q.front(); q.pop();
        if (ok(tmp)) { res ++; continue; }
        if (dist[tmp.x][tmp.y][tmp.z] >= k) continue;

        REP(i, n) if (tmp.x >= e[i][0] && tmp.y >= e[i][1] && tmp.z >= e[i][2]){
            int m = tmp.x + e[i][3];
            int n = tmp.y + e[i][4];
            int p = tmp.z + e[i][5];
            if (m <= 4 && n <= 4 && p <= 4 && dist[m][n][p] == 0) {
                dist[m][n][p] = 1 + dist[tmp.x][tmp.y][tmp.z];
                q.push(state(m, n, p));
                //printf("%d %d %d -> %d %d %d\n", tmp.x, tmp.y, tmp.z, m, n, p);
            }
        }
    }
    if (res == 0) { printf("-1"); return 0; }
    printf("%d\n", res);
    FOR(i, u, 4)
    FOR(j, v, 4)
    FOR(l, t, 4)
    if (dist[i][j][l]) printf("%d %d %d %d\n", i, j, l, dist[i][j][l]);
}
