using namespace std;
#include <stdio.h>
#include <algorithm>
const int N = 500 + 5;
const int oo = 1e9 + 7;
int n, k;
int f[N][N], g[N][N], res = oo;
int main() {
    scanf("%d%d", &n, &k);
    while (k--) {
        int u, v;
        scanf("%d%d", &u, &v);
        f[u][v] = oo;
        g[u][v] = oo;
    }
    f[1][1] = 0;
    for (int i = 2; i <= n; i++) {
        if (f[i][1] != oo) f[i][1] = i-1;
        if (f[1][i] != oo) f[1][i] = i-1;
    }
    for (int i = 2; i <= n; i++)
    for (int j = 2; j <= n; j++) if (f[i][j] != oo)
        f[i][j] = min(f[i-1][j-1], min(f[i][j-1], f[i][j-1])) + 1;
    g[1][n] = 0;
    for (int i = 2; i <= n; i++)
        if (g[i][n] != oo) g[i][n] = i-1;
    for (int i = 1; i < n; i++)
        if (g[1][i] != oo) g[1][i] = n-i;
    for (int i = 2; i <= n; i++)
    for (int j = n-1; j >= 1; j--) if (g[i][j] != oo)
        g[i][j] = min(g[i-1][j+1], min(g[i-1][j], g[i][j+1])) + 1;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) res = min(res, max(f[i][j], g[i][j]));

    for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%12d", f[i][j]); printf("\n"); }

    for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%12d", f[i][j]); printf("\n"); }

    printf("%d", res);
}
