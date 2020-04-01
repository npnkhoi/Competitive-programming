#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;
int n, k, a[N], b[N], f[N], dp[N][N], res;

int main() {
    freopen("phonetalks.inp", "r", stdin);
    freopen("phonetalks.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
    a[n+1] = 86401;
    f[0] = 0;
    for (int i = 1; i <= n; i++) f[i] = max(f[i-1] + 1, a[i]) + b[i] - 1;
    for (int i = k+1; i <= n+1; i++) res = max(res, a[i] - f[i-k-1] - 1);

    for (int i = 1; i <= n; i++) dp[i][0] = f[i];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++)
        dp[i][j] = min(max(dp[i-1][j] + 1, a[i]) + b[i] - 1, dp[i-1][j-1]);
    res = max(res, 86400 - dp[n][k]);

    printf("%d", res);
}
