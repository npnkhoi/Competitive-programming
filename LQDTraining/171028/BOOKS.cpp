#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
const long long oo = 1e15 + 7;
int n, k;
long long a[N], dp[N][N];

int main() {
    freopen("BOOKS.inp", "r", stdin);
    freopen("BOOKS.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] += a[i-1];
    }
    for (int i = 1; i <= n; i++) dp[i][1] = a[i];
    for (int j = 2; j <= k; j++) dp[1][j] = oo;

    for (int i = 2; i <= n; ++i)
    for (int j = 2; j <= k; ++j) {
        dp[i][j] = oo;
        if (i >= j)
        for (int l = j; l <= i; l++)
            dp[i][j] = min(dp[i][j], max(dp[l-1][j-1], a[i] - a[l-1]));
    }
    printf("%lld\n", dp[n][k]);
}
