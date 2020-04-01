#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int m, n, x, y, a[N][N], water[N][N];
bool mark[N][N];
queue<pair<int, int>> q;
long long res;
#define mp make_pair
bool inside(int x, int y) {
    return 1 <= x && x <= m && 1 <= y && y <= n;
}
int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    scanf("%d%d", &x, &y);
    if (a[x][y] >= 0) {
        printf("0\n");
        return 0;
    }
    res = -a[x][y];
    mark[x][y] = 1;
    water[x][y] = a[x][y];

    q.push(mp(x, y));
    while (!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        mark[u][v] = 0;
        q.pop();
        for (int love = 0; love < 8; love++) {
            int z = u + dx[love];
            int t = v + dy[love];
            if (inside(z, t)) {
                int tmp = max(a[z][t], water[u][v]);
                if (water[z][t] > tmp) {
                    res += water[z][t] - tmp;
                    water[z][t] = tmp;
                    if (!mark[z][t]) {
                        q.push(mp(z, t));
                        mark[z][t] = 1;
                    }
                }
            }
        }
    }
    printf("%lld", res);
}
