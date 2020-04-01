#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 105;
const int oo = 1e9 + 7;
int n, s, sb, a[N], b[N], f[2][N][N*N];

int main() {
    freopen("donuoc.inp", "r", stdin);
    freopen("donuoc.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        sb += b[i];
    }
    //cerr << s << " " << sb << "\n";
    //f[x][i][j]: maxSumA khi chon i chai tu x chai, sumB = j

    int cur = 0, pre = 1;
    for (int i = 0; i <= n; i++)
    for (int j = 0; j <= sb; j++) f[cur][i][j] = -oo;
    f[cur][0][0] = 0;

    for (int x = 1; x <= n; x++) {
        cur ^= 1; pre ^= 1;
        for (int i = 0; i <= n; i++)
        for (int j = 0; j <= sb; j++) {
            f[cur][i][j] = f[pre][i][j];
            if (i >= 1 && j >= b[x]) f[cur][i][j] = max(f[cur][i][j], f[pre][i-1][j - b[x]] + a[x]);
            //printf("f(%d, %d, %d) = %d\n", x, i, j, f[cur][i][j]);
        }
    }
    for (int i = 0; i <= n; i ++) {
        int tmp = -1;
        for (int j = s; j <= sb; j++) tmp = max(tmp, f[cur][i][j]);
        if (tmp >= 0) {
            printf("%d %d", i, s - tmp);
            exit(0);
        }
    }
}
