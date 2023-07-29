#include <bits/stdc++.h>
using namespace std;

const int lim = 1e3 + 1, N = 1e3 + 5;

int n, cc = 0, x[N], y[N];
bool mark[N][N];
int row[N][N], col[N][N], sz[lim * lim + 2];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

bool check(int r, int c, int dir) {
    int u = r + dx[dir], v = c + dy[dir];
    if (u < 0 || u > lim + 1 || v < 0 || v > lim + 1 || mark[u][v]) return false;
    if (dir == 0) return row[r][c] == 0;
    if (dir == 1) return col[c+1][r] == 0;
    if (dir == 2) return row[r+1][c] == 0;
    if (dir == 3) return col[c][r] == 0;
}

void dfs(int r, int c) {
    // printf("dfs %d %d\n", r, c);
    mark[r][c] = true;
    sz[cc] ++;
    for (int dir = 0; dir < 4; ++ dir) {
        if (check(r, c, dir)) {
            int u = r + dx[dir], v = c + dy[dir];
            dfs(u, v);
        }
    }
}

int main() {
    // freopen("C.inp", "r", stdin);
    cin >> n;
    for (int i = 0; i <= n; ++ i) cin >> x[i] >> y[i];
    x[n+1] = x[0]; y[n+1] = y[0];

    for (int i = 1; i <= n; ++ i) {
        int u, v;
        if (x[i] == x[i-1]) {
            u = min(y[i], y[i-1]);
            v = max(y[i], y[i-1]);
            row[x[i]][u] ++;
            row[x[i]][v] --;
            // printf("row %d %d %d\n", x[i], u, v);
        } else {
            u = min(x[i], x[i-1]);
            v = max(x[i], x[i-1]);
            col[y[i]][u] ++;
            col[y[i]][v] --;

            // printf("col %d %d %d\n", y[i], u, v);
        }
    }
    for (int i = 1; i <= lim; ++i) {
        for (int j = 2; j <= lim + 1; j ++) {
            row[i][j] += row[i][j-1];
            col[i][j] += col[i][j-1];
        }
    }

    // cerr << col[2][1];
    // return 0;

    int res = 0;
    for (int i = 0; i <= lim + 1; i++) {
        for (int j = 0; j <= lim + 1; j ++) {
            if (!mark[i][j]) {
                dfs(i, j);
                cc ++;
                if (cc > 1) res = max(res, sz[cc - 1]);
                // cerr << sz[cc-1] << '\n';
            }
        }
    }
    cout << res;
}
