#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
int a[N][N], s[N][N];
int m, n, res;
int sum(int x, int y, int u, int v) {
    return s[u][v] - s[u][y-1] - s[x-1][v] + s[x-1][y-1];
}
int main() {
    scanf("%d %d", &m, &n);
    char ch;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
        scanf(" %c", &ch);
        a[i][j] = (ch == 'X');
        s[i][j] = a[i][j] + s[i][j-1] + s[i-1][j] - s[i-1][j-1];
    }
    int pre;
    for (int u = 1; u <= m; u++)
    for (int v = u; v <= m; v++) {
        pre = -1;
        for (int x = 1; x <= n; x++)
        if (a[u][x] || a[v][x]) pre = -1;
        else if (sum(u, x, v, x) == 0)
        if (pre != -1)
            res = max(res, (x-pre+1) * (v-u+1));
        else pre = x, res = max(res, v-u+1);
    }
    printf("%d\n", res);
}
