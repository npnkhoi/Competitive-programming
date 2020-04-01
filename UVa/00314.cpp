using namespace std;
#include <stdio.h>
#include <string.h>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

#define mp make_pair
#define fi first
#define se second

const int N = 55;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int a[N][N], d[N][N][5];
queue<pair<pair<int, int>, int> > q;

void check(int u, int v, int d2, int i, int j, int d1) {
    if (u <= 0 || u >= m || v <= 0 || v >= n) return;
    for (int x = min(i, u); x <= max(i, u); x++)
    for (int y = min(j, v); y <= max(j, v); y++)
        if (a[x][y]) return;

    if (d[u][v][d2] == -1 && a[u][v] == 0) {
        d[u][v][d2] = d[i][j][d1] + 1;
        q.push(mp(mp(u, v), d2));
        //printf("%d %d %d, %d %d %d: %d %d\n", u, v, d2, i, j, d1, d[u][v][d2], d[i][j][d1]);
    }
}

int main () {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    while (1) {
        scanf("%d %d", &m, &n);
        //printf("---%d %d\n", m, n);
        if (!m && !n) break;

        memset(a, 0, sizeof a);
        memset(d, -1, sizeof d);

        for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if (x) a[i][j] = a[i][j+1] = a[i+1][j] = a[i+1][j+1] = 1;
        }

        int xx, yy, x, y, di;
        string str;

        scanf("%d %d %d %d", &xx, &yy, &x, &y);
        cin >> str;

        if (str == "north") di = 0;
        else if (str == "east") di = 1;
        else if (str == "south") di = 2;
        else di = 3;

        if (!a[x][y]) d[x][y][di] = 0, q.push(mp(mp(x, y), di));
        /*if (!a[x+1][y]) d[x+1][y][di] = 0; q.push(mp(mp(x+1, y), di));
        if (!a[x][y+1]) d[x][y+1][di] = 0; q.push(mp(mp(x, y+1), di));
        if (!a[x+1][y+1]) d[x+1][y+1][di] = 0; q.push(mp(mp(x+1, y+1), di));*/

        while (!q.empty()) {
            int i = q.front().fi.fi,
                j = q.front().fi.se,
                di = q.front().se;
            q.pop();

            for (int k = 1; k <= 3; k++) {
                int u = i + dx[di]*k, v = j + dy[di]*k;
                check(u, v, di, i, j, di);
            }

            check(i, j, (di + 1) % 4, i, j, di);
            check(i, j, (di + 3) % 4, i, j, di);
        }

        int res = int(1e9);
        for (int k = xx; k <= xx + 0; k++)
        for (int l = yy; l <= yy + 0; l++)
        for (int i = 0; i < 4; i++)
            if (d[k][l][i] != -1) res = min(res, d[k][l][i])
            //,printf("%d %d %d: %d\n", k, l, i, d[k][l][i])
            ;
        if (res == int(1e9)) printf("-1\n");
            else printf("%d\n", res);
    }
}
