using namespace std;
#include <stdio.h>
#include <algorithm>

const int K = 8;
const int N = 1e3 + 10;

int n, k, a[K][N], pos[K][N], f[N], res;

bool cut(int x, int y) {
    for (int i = 0; i < k; i++)
    if (pos[i][x] >= pos[i][y]) return true;
    return false;
}
int main () {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    for (int j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
        pos[i][a[i][j]] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++)
            if (!cut(a[0][j], a[0][i]))
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }

    printf("%d", res);
}
