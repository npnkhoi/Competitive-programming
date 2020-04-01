#include <cstdio>
#include <algorithm>
using namespace std;
#define task "coins"

const int N = 1e5 + 5;
const int md = 123456789;
const int oo = 1e9 + 7;
const int TYPE = 100;
int n, f[TYPE + 5][N], g[N], cnt[TYPE + 5];
void trace(int money, int type) {
    if (money == 0) {
        for (int i = 1; i <= TYPE; i++) if (cnt[i])
        printf("%d %d\n", cnt[i], i);
    } else
    for (int j = type; j >= 1; j--)
    if (j *j <= money && g[money - j*j] == g[money] - 1) {
        cnt[j] ++;
        trace(money - j*j, j);
        break;
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    f[0][0] = 1;
    for (int i = 1; i <= TYPE; i++)
    for (int j = 0; j <= n; j++) {
        f[i][j] = f[i-1][j];
        if (j >= i*i) f[i][j] = (f[i][j] + f[i][j - i*i]) % md;
    }
    printf("%d\n", f[TYPE][n]);
    g[0] = 0;
    for (int i = 1; i <= n; i++) {
        g[i] = oo;
        for (int j = 1; j <= TYPE && j*j <= i; j++)
        g[i] = min(g[i], g[i - j*j] + 1);
    }
    printf("%d\n", g[n]);
    trace(n, TYPE);
}
