using namespace std;
#include <iostream>
#include <stdio.h>
#include <queue>

const int N = 1e3 + 10;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue< pair<int, int> > q;
int m, n, res;
char a[N][N];
bool been[N][N], cont;
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
        scanf(" %c", &a[i][j]);
        if (a[i][j] == 'E') q.push(make_pair(i, j)), been[i][j] = 1;
    }

    cont = 1;

    while (cont) {
        int s = q.size();
        while (s--) {

            pair<int, int> x = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int u = x.first + dx[i], v = x.second + dy[i];
                if (u >= 1 && u <= m && v >= 1 && v <= n
                && (!been[u][v]) && a[u][v] != 'T') {
                    q.push(make_pair(u, v)), been[u][v] = 1;
                    if (a[u][v] == 'S') cont = 0;
                        else res += a[u][v] - '0';
                }
            }

        }
    }
    cout << res;
}
