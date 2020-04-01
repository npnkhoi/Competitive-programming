using namespace std;
#include <stdio.h>
#include <algorithm>
#include <string.h>

const int N = 1e3 + 10;
int n, p, k, a[N], b[N];
void sub1() {
    //printf("sub1\n");
    int f[n+2][p+2][k+2][k+2];
    memset(f, 0, sizeof f);
    /*for (int i = 1; i <= n; i++)
    for (int j = 1; j <= p; j++)
    for (int x = 0; x <= k; x++)
    for (int y = 0; y <= k; y++) printf("%d", f[i][j][x][y]);
    printf("\n");*/

    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= p; j++)
    for (int x = 0; x <= k; x++)
    for (int y = 0; y <= k; y++) {
        int tmp = f[i-1][j][x - (x>0)][y - (y>0)];
        if (x <= 1 && j > 0) tmp = max(tmp, f[i-1][j-1][k][y - (y>0)]);
        if (y <= 1 && j > 0) tmp = max(tmp, f[i-1][j-1][x - (x>0)][k]);
        if (x <= 1 && y <= 1 && j > 1) tmp = max(tmp, f[i-1][j-2][k][k]);
        f[i][j][x][y] = tmp + ((a[i]&&x>0)||(b[i]&&y>0));
        //printf("%d, %d, %d, %d = %d\n", i, j, x, y, f[i][j][x][y]);
    }
    int res = 0;
    for (int x = 0; x <= k; x++)
    for (int y = 0; y <= k; y++)
        res = max(res, f[n][p-(x>0)-(y>0)][x][y]);
    printf("%d\n", res);
}

void sub2() {
    int res = 0;
    for (int i = 1; i <= n; i++) res += a[i] || b[i];
    printf("%d", res);
}
int main() {
    scanf("%d %d %d", &n, &p, &k);
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int pos;
        scanf("%d", &pos);
        a[pos] = 1;
    }
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int pos;
        scanf("%d", &pos);
        b[pos] = 1;
    }

    if (p <= (2*n)/k) sub1();
    else sub2();
}
