#include <cstdio>
using namespace std;
#define task "954F"
const int N = 1e6 + 5;
const int md = 1e9 + 7;
int a[N][5], f[N][5], m, n;
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        for (int j = y; j <= z; j++) a[j][x] = 1;
    }
    f[1][2] = 1;
    for (int i = 2; i <= m; i ++) {
        if (a[i][1] == 0) f[i][1] = (f[i-1][1] + f[i-1][2]) % md;
        if (a[i][2] == 0) f[i][2] = (f[i-1][1] + f[i-1][2] + f[i-1][3]) % md;
        if (a[i][3] == 0) f[i][3] = (f[i-1][2] + f[i-1][3]) % md;
    }
    printf("%d", f[m][2]);
}
