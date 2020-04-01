using namespace std;
#include <stdio.h>
#include <iostream>
#include <string.h>

const int N = 110;
int tc, m, n;
int a[N][N], memo[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int f(int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];

    int tmp = 0;
    for (int k = 0; k < 4; k++) {
        int u = i + dx[k], v = j + dy[k];
        if (u >= 1 && u <= m && v >= 1 && v <= n && a[u][v] < a[i][j])
            tmp = max(tmp, f(u, v));
    }

    memo[i][j] = tmp + 1;
    return memo[i][j];
}
int main () {
    scanf("%d", &tc);
    while (tc --) {
        string name;
        cin >> name;
        printf("%s: ", name.c_str());
        scanf("%d %d", &m, &n);
        for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
        memset(memo, -1, sizeof memo);

        int res = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) res = max(res, f(i, j));
        }
        printf("%d\n", res);
    }
}
