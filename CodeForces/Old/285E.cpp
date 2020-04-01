using namespace std;
#include <stdio.h>
const int N = 1010;
const int md = 1e9 + 7;
int dp[N][N][3];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    dp[1][0][0] = 1;
    for (int i = 2; i <= n; i++)
    for (int j = 0; j <= k; j++) {
        dp[i][j][1] = (dp[i-1][j][0] + dp[i-1][j][1]) % md;
        if (j >= 1) dp[i][j][0] = (dp[i][j][0] + 2*dp[i-1][j-1][0]) % md;
        if (j >= 2) dp[i][j][0] = (dp[i][j][0] + dp[i-1][j-2][1]) % md;
        if (i > 2) dp[i][j][0] = (dp[i][j][0] + (i-2)*dp[i-1][j][0]) % md;
    }
    for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) printf("%3d", dp[i][j][0]);
    printf("\n"); }
    printf("\n");
    for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) printf("%3d", dp[i][j][1]);
    printf("\n"); }
    printf("%d %d", dp[n][k][0], dp[n][k][1]);
}
