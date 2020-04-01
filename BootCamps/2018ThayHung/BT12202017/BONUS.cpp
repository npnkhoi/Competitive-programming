#include <cstdio>
using namespace std;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        scanf("%lld", &a[i][j]);
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }
    for (int i = k; i <= n; i++)
    for (int j = k; j <= n; j++)
        res = max(res, a[i][j] - a[i][j-k] - a[i-k][j] + a[i-k][j-1]);
    printf("")
}
