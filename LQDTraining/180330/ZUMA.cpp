#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 505;
int n, a[N], f[N][N];
int main() {
    freopen("zuma.inp", "r", stdin);
    freopen("zuma.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i >= 1; i--)
    for (int j = i; j <= n; j++) {
        f[i][j] = j - i + 1;
        for (int k = i; k < j; k++)
            f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
        if (a[i] == a[j])
            if (j - i + 1 >= 3) f[i][j] = min(f[i][j], f[i+1][j-1]);
            else f[i][j] = min(f[i][j], 1);
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%4d", f[i][j]);
        cerr << "\n";
    }*/

    printf("%d", f[1][n]);
}
