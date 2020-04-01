using namespace std;
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int N = 510;
const int oo = 1e9 + 7;
int n, memo[N][N], a[N];
int dp(int x, int y) {
    if (y - x <= 0) return 1;
    if (memo[x][y] != -1) return memo[x][y];

    int s = oo;

    if (a[x] == a[y]) s = min(s, dp(x + 1, y - 1));
    for (int k = x; k < y; k++) s = min(s, dp(x, k) + dp(k+1, y));
    memo[x][y] = s;
    return s;
}
int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(memo, -1, sizeof memo);
    printf("%d\n", dp(1, n));
}
