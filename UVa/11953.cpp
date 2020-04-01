using namespace std;
#include <stdio.h>

const int N = 105;
char a[N][N], n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void flood(int x, int y) {
    a[x][y] = '.';
    for (int z = 0; z < 4; z++) {
        int u = dx[z] + x, v = y + dy[z];
        if (u >= 0 && v >= 0 && u < n && v < n && a[u][v] == 'x')
            flood(u, v);
    }
}

int main() {
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf(" %c", &a[i][j]);

        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 'x')
            for (int z = 0; z < 4; z++) {
                int u = i + dx[z], v = j + dy[z];
                if (a[u][v] == '@') a[u][v] = 'x';
            }
        int res = 0;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        if (a[i][j] == 'x') res ++, flood(i, j);
        printf("Case %d: %d\n", tc, res);
    }
}
