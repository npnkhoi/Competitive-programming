#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e3 + 5;
int m, n, x, y, u, v, a[N][N];
int main() {
    freopen("HCN.inp", "r", stdin);
    freopen("HCN.out", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
    scanf("%d%d%d%d", &x, &y, &u, &v);
    long long s = 0;
    for (int i = x; i <= u; ++i)
    for (int j = y; j <= v; ++j) s += a[i][j];
    printf("%lld", s);
}

