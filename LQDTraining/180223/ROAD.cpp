#include <bits/stdc++.h>
using namespace std;
#define task "ROAD"
const int N = 105;
const int md = 1e9;
int m, n, a[N][N], dp[N][N];

int GCD(int x, int y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);

        if (j == 1) dp[i][j] = 1;
        for (int x = 1; x <= i; x++)
        for (int y = 1; y <= min(j, n-1); y++)
            if ((x != i || y != j) && GCD(a[x][y], a[i][j]) != 1)
            dp[i][j] = (dp[i][j] + dp[x][y]) % md;
    }
    /*for (int i = 1; i <= m ; i++) {
        for (int j = 1; j <= n; j++) cerr << dp[i][j];
        cerr << "\n";
    }*/

    int res = 0;
    for (int i = 1; i <= m; i++) res = (res + dp[i][n]) % md;
    printf("%d", res);
}
