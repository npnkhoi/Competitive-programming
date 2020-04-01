#include <cstdio>
using namespace std;
const int N = 1005;
const int oo = 1e9 + 7;
int m, n, a[N][N];
bool inside(int x, int y) {
    return 1 <= x && x <= m && 1 <= y && y <= n;
}
int bfs(int startCol) {
    int x = 1, y = startCol, direct = 0;
    int cnt = 0;
    while (1) {
        //printf("%d %d %d\n", x, y, direct);
        cnt ++;
        if (a[x][y] == 0)
            switch (direct) {
                case 0: {
                    y ++, direct = 3;
                    break;
                }
                case 1: {
                    x --, direct = 2;
                    break;
                }
                case 2: {
                    y --, direct = 1;
                    break;
                }
                case 3: {
                    x ++, direct = 0;
                    break;
                }
            }
        else
            switch (direct) {
                case 0: {
                    y --, direct = 1;
                    break;
                }
                case 1: {
                    x ++, direct = 0;
                    break;
                }
                case 2: {
                    y ++, direct = 3;
                    break;
                }
                case 3: {
                    x --, direct = 2;
                    break;
                }
            }
        if (!inside(x, y))  {
            if (x == m+1) return cnt;
            else return oo;
        }
    }
}
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        scanf("%d", &a[i][j]);

    int minPath = oo, cnt;
    for (int i = 1; i <= n; i++) {
        int tmp = bfs(i);
        if (tmp < minPath) {
            minPath = tmp;
            cnt = 1;
        } else if (tmp == minPath) cnt ++;
    }
    if (minPath != oo) printf("%d %d", minPath, cnt);
    else printf("0 0");
}
