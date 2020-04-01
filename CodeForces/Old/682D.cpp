using namespace std;
#include <stdio.h>
#include <cstring>
#include <algorithm>
int n, m, p;
const int N = 1010;
const int K = 12;
char a[N], b[N];
int f[N][N][K][3];
int main() {
    scanf("%d%d%d ", &m, &n, &p);
    scanf("%s %s", a+1, b+1);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    for (int k = 1; k <= p; k++) {
        f[i][j][k][1] = (a[i] == b[j]) ? 1 + max(f[i-1][j-1][k][1], f[i-1][j-1][k-1][0]) : 0;
        f[i][j][k][0] =
        max(max(f[i][j-1][k][0], f[i][j-1][k][1]), max(f[i-1][j][k][0], f[i-1][j][k][1]));
    }
    printf("%d", max(f[m][n][p][0], f[m][n][p][1]));
}
