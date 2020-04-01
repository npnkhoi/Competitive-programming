#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;
int n;
long long a[N][N], tmp[2], res;
long long sum(int x, int y, int u, int v) {
    return a[u][v] - a[x-1][v] - a[u][y-1] + a[x-1][y-1];
}
int main() {
    //freopen("square.inp", "r", stdin);
    //freopen("square.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        scanf("%lld", &a[i][j]);
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }

    res = - 1e18;

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        int cur = 0;
        tmp[0] = tmp[1] = 0;
        for (int k = 0; i - k >= 1 && i + k <= n && j - k >= 1 && j + k <= n; k++) {
            tmp[cur] = sum(i-k,  j-k, i+k, j+k) - tmp[cur^1];
            //printf("Case 1: %d %d %d %lld\n", i, j, k, tmp[cur]);
            res = max(res, tmp[cur]);
            cur ^= 1;
        }
    }

    for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++) {
        int cur = 0;
        tmp[0] = tmp[1] = 0;
        for (int k = 0; i - k >= 1 && i + k < n && j - k >= 1 && j + k < n; k++) {
            tmp[cur] = sum(i-k,  j-k, i+k+1, j+k+1) - tmp[cur^1];
            //printf("Case 2: %d %d %d %lld\n", i, j, k, tmp[cur]);
            res = max(res, tmp[cur]);
            cur ^= 1;
        }
    }

    printf("%lld", res);
}
