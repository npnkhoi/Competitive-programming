#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
const int N = 25;
int tc, n, a[N][4], f[N][4];
int main() {
    freopen("PAINT.inp", "r", stdin);
    freopen("PAINT.out", "w", stdout);
    scanf("%d", &tc);
    REP(z, tc) {
        scanf("%d", &n);
        FOR(i, 1, n) FOR(j, 0, 2) scanf("%d", &a[i][j]);
        FOR(j, 0, 2) f[1][j] = a[1][j];
        FOR(i, 2, n) {
            f[i][0] = a[i][0] + min(f[i-1][1], f[i-1][2]);
            f[i][1] = a[i][1] + min(f[i-1][0], f[i-1][2]);
            f[i][2] = a[i][2] + min(f[i-1][0], f[i-1][1]);
        }
        printf("%d\n", min(f[n][0], min(f[n][1], f[n][2])));
    }
}
