#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 505;
int a[N], b[N], g[N], f[N][N], m, n, res;
int main() {
    freopen("lcis.inp", "r", stdin);
    freopen("lcis.out", "w", stdout);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    for (int i = 1; i <= m; i++)
    for (int j = n; j >= 1; j--) if (a[i] == b[j]) {
        f[i][j] = 1;
        for (int k = 1; k < j; k++) if (b[k] < b[j])
            f[i][j] = max(f[i][j], g[k] + 1);
        g[j] = max(g[j], f[i][j]);
        res = max(res, f[i][j]);
    }
    printf("%d", res);
}
