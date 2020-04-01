#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int n, a[N], s[N], f[N][N], res;
int sum(int l, int r) { return s[r] - s[l-1];}
int main() {
    freopen("ivan.inp", "r", stdin);
    freopen("ivan.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        a[i] = a[n+i] = val % 2;
    }
    for (int i = 1; i <= 2*n; i++) s[i] = s[i-1] + a[i];

    for (int i = 1; i <= 2*n; i++) f[i][i-1] = 0;
    for (int i = 2*n; i >= 1; i--)
    for (int j = i; j <= 2*n; j++)
        f[i][j] = sum(i, j) - min(f[i+1][j], f[i][j-1]);
    for (int i = 1; i <= n; i++) res += (2 * f[i+1][i+n-1] < s[n]);

    /*for (int i = 1; i <= 2*n; i++) {
        for (int j = 1; j <= 2*n; j++) printf("%4d", f[i][j]);
        cerr << "\n";
    }*/

    printf("%d", res);
}
