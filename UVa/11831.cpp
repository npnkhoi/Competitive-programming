using namespace std;
#include <stdio.h>
#include <iostream>
int x, y, dir, res;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
const int N = 110;
char a[N][N];
int main() {
    //freopen("test.inp","r",stdin);
    while (1) {
        int n, m , q;
        int dir, x, y;
        scanf("%d %d %d", &n, &m ,&q);
        //cout << n << m << q;
        if (m == 0 && n == 0 && q == 0) break;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf(" %c", &a[i][j]);
            if ('A' <= a[i][j] && a[i][j] <= 'Z') {
                x = i; y = j;
                if (a[i][j] == 'N') dir = 0;
                else if (a[i][j] == 'S') dir = 2;
                else if (a[i][j] == 'L') dir = 1;
                else dir = 3;
            }
        }
        //cout << dir;
        int res = 0;
        while (q--) {
            char cmd;
            scanf(" %c", &cmd);
            //cout << cmd;
            if (cmd == 'D') dir = (dir + 1) % 4;
            else if (cmd == 'E') dir = (dir + 3) %4;
            else {
                //cout  << 1;
                x += dx[dir];
                y += dy[dir];
                if (x >= 0 && x < n && y >=0 && y < m && a[x][y] != '#') {
                    res += (a[x][y] == '*');
                    a[x][y] = '.';
                }   else x -= dx[dir], y -= dy[dir];
            }
            //cout << x << " " << y << " " << dir << "\n";
        }
        cout << res << endl;
    }
}
