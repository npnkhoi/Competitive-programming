#include <bits/stdc++.h>
using namespace std;
const int N = 15e3 + 5;
const int oo = 1e9 + 7;
int dp[N][N], a[N];
int main() {
    freopen("QBSEGPAR.inp", "r", stdin);
    freopen("QBSEGPAR.ans", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i-1];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][1] = a[i];
        for (int j = 2; j <= min(i, k); j++) {
            dp[i][j] = oo;
            for (int l = j-1; l < i; l++)
            dp[i][j] = min(dp[i][j], max(dp[l][j-1], a[i] - a[l]));
        }
    }
    printf("%d\n", dp[n][k]);
}
