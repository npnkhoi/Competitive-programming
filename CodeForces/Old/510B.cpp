using namespace std;
#include <stdio.h>
#include <iostream>

const int N = 61;
char a[N][N];
bool been[N][N];
int m, n, cntE, cntV;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool dfs(int i, int j) {
    been[i][j] = 1; cntV ++;
    for (int x = 0; x < 4; x++) {
        int u = i + dx[x];
        int v = j + dy[x];
        if (a[u][v] == a[i][j]) {
            cntE ++;
            if (!been[u][v]) dfs(u, v);
        }
    }
    return 0;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        scanf(" %c", &a[i][j]);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    if (!been[i][j]) {
        cntV = cntE = 0;
        dfs(i, j);
        if (cntE != 2*(cntV-1)) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
