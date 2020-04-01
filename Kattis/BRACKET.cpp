#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 5005;
int n, a[N], s[N], minn[N][N], maxx[N][N];
int sum(int l, int r) {return s[r] - s[l-1];}
bool check(int l, int r) {
    if (minn[1][l-1] >= 0)
    if (sum(1, l-1) - maxx[l][r] >= 0)
    if (sum(1, r) - 2 * sum(l, r) + minn[r+1][n] >= 0)
    return (sum(1, n) - 2 * sum(l, r) == 0);
    return 0;
}
int main() {
    //freopen("bracket.inp", "r", stdin);
    char ch;
    while (scanf(" %c", &ch) != EOF) {
        ++ n;
        if (ch == '(') a[n] = 1;
        else a[n] = -1;
        s[n] = s[n-1] + a[n];
    }
    for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) {
        maxx[i][j] = max(maxx[i][j-1], s[j] - s[i-1]);
        minn[i][j] = min(n + 5, min(minn[i][j-1], s[j] - s[i-1]));
        //printf("%d %d: %d %d\n", i, j, minn[i][j], maxx[i][j]);
    }

    if (check(1, 0)) {
        printf("possible\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) if (check(i, j)) {
        printf("possible\n");
        exit(0);
    }
    printf("impossible\n");
    return 0;
}
