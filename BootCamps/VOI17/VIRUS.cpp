using namespace std;
#include <stdio.h>
#include <algorithm>
#include <cstring>
const int N = 3000 + 10;
const int K = 12;
int q, s, n, f[N][N][K];
char str[N];
int main() {
    freopen("VIRUS.inp", "r", stdin);
    freopen("VIRUS.out", "w", stdout);
    scanf("%d %s", &q, str+1);
    n = strlen(str+1);
    for (int i = 1; i < n; i++)
    for (int j = i+1; j <= n; j++)
    for (int l = 0; l <= 10; l++) {
        if (str[i] == str[j]) f[i][j][l] = 1 + f[i-1][j-1][l];
        else if (l == 0) f[i][j][l] = 0;
        else f[i][j][l] = 1 + f[i-1][j-1][l-1];
    }
    while (q--) {
        int k;
        scanf("%d", &k);
        int res = 0;
        for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
        if (f[i][j][k] >= j-i) res = max(res, j-i);
        printf("%d\n", res);
    }
}
