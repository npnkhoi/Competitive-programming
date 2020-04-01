#include <bits/stdc++.h>
using namespace std;

const int N = 405;

int m, n, a[N][N], res;
int sum(int x, int y, int u, int v) {
    return a[u][v] - a[x-1][v] - a[u][y-1] + a[x-1][y-1];
}

int main() {
    freopen("dinner.inp", "r", stdin);
    freopen("dinner.out", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
        char ch;
        scanf(" %c", &ch);
        a[i][j] = (ch != '.') + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }

    res = 0;
    for (int u = 1; u <= m; u++)
    for (int v = u; v <= m; v++) {
        int cnt = 0, tmp = 0;

        for (int x = 1; x <= n; x++) {
            if (sum(u, x, v, x) == 0) cnt ++;
            else cnt = 0;
            //printf("%d %d %d: %d\n", u, v, x, cnt);
            tmp = max(tmp, cnt);
        }
        if (tmp > 0) res = max(res, 2*(v-u+1 + tmp) - 1);
    }
    printf("%d", res);
}
