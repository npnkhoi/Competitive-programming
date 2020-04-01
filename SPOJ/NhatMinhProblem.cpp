using namespace std;
#include <stdio.h>
int n, m, f[20][10];

int main () {
    n = 17; m = 4;
    for (int i = 0; i <= n; i++) f[i][0] = 1;
    f[1][1] = 1;

    for (int i = 2; i <= n; i++)
    for (int j = 1; j <= m; j++) f[i][j] = f[i-1][j] + f[i-2][j-1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) printf("%5d", f[i][j]);
        printf("\n");
    }
}
