using namespace std;
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>

const int N = 255;
int n, m, a[N][N], num[N], v[N], f[N][N];
bool cannot = 0;
int x, s;

void dfs(int u) {
    if (cannot) return;
    if (num[u] == 0) x++; else x--;

    for (int v = 1; v <= n; v++)
    if (a[u][v] == 0 && v != u)
    if (num[v] == -1) {
        num[v] = 1 - num[u];
        dfs(v);
    }
        else if (num[v] == num[u]) cannot = 1;
}
int main () {
    freopen("partition.inp", "r", stdin);
    freopen("partition.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);

    memset(num, -1, sizeof num);
    cannot = 0; m = 0;

    for (int i = 1; i <= n && !cannot; i++) if (num[i] == -1) {
        x = 0;
        num[i] = 0;

        dfs(i);

        x = abs(x);
        v[++m] = x; s += x;
        //printf("%d: %d %d\n",i, x, s);
    }

    if (cannot) {
        printf("Impossible");
        return 0;
    }

    for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= s/2; j++) {
            if (v[i] <= j) f[i][j] = max(f[i-1][j], v[i] + f[i-1][j - v[i]]);
                else f[i][j] = f[i-1][j];
            //printf("%d ", f[i][j]);
        }
        //printf("\n");
    }

    printf("%d", s - 2*f[m][s/2]);
}
