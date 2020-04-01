#include <bits/stdc++.h>
using namespace std;

const int MASK = (1 << 20) + 5;
const int N = 22;
const long long oo = 1e18 + 7;

int n, m;
long long dp[MASK][N], c[N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            c[i][j] = oo;
        }
    }
    for (int i = 1; i <= m; ++ i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u --; v --;
        c[u][v] = min(c[u][v], 1LL * w);
    }
    for (int mask = 0; mask < (1 << n); ++ mask) {
        for (int i = 0; i < n; ++ i) {
            dp[mask][i] = oo;
            if ((mask & (1 << i)) == 0) {
                continue;
            }
            if (__builtin_popcount(mask) == 1) {
                if (i == 0) dp[mask][i] = 0;
                continue;
            }
            for (int j = 0; j < n; ++ j) {
                if ((mask & (1 << j) == 0) || i == j) continue;
                dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + c[j][i]);
            }
        }
    }
    long long res = oo;
    for (int i = 1; i < n; ++ i) res = min(res, dp[(1 << n) - 1][i] + c[i][0]);
    printf("%lld", res);
}