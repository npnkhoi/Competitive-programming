using namespace std;
#include <stdio.h>
#include <algorithm>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

const int N = 23;
const int oo = 1e9;
char a[N][N], land;
int xx, yy, cnt, n, m;

void flood(int x, int y) {
    cnt ++; a[x][y] = land-1;
    for (int z = 0; z < 4; z++) {
        int u = x + dx[z], v = (y + dy[z] + n) % n;
        if (u >= 0 && u < m && a[u][v] == land) flood(u, v);
    }
}
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    while (scanf("%d %d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf(" %c", &a[i][j]);

        scanf("%d %d", &xx, &yy);
        land = a[xx][yy];
        flood(xx, yy);

        int res = 0;

        for (int i = 0; i < m ; i++)
        for (int j = 0; j < n ; j++)
        if (a[i][j] == land)
            cnt = 0, flood(i, j), res = max(res, cnt);

        printf("%d\n", res);
    }
}
