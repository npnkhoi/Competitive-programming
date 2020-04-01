using namespace std;
#include <bits/stdc++.h>

const int N = 100;
int dx[6] = {3, 2, 1, 1, 0, 0};
int dy[6] = {0, 1, 2, 0, 3, 1};

int n;
int a[N][N], f[N][N];
bool inRange(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= n;}

int main() {
    int t;
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    f[1][1] = 0;
    for (int j = 2; j <= n; j ++) {
        int tmp = f[1][j-1];
        if (j>3) tmp = min(tmp, f[1][j-3]);
        f[1][j] = tmp + 3*t + a[1][j];
    }
    for (int i = 2; i <= n; i ++) {
        int tmp = f[i-1][1];
        if (i>3) tmp = min(tmp, f[i-3][1]);
        f[i][1] = tmp + 3*t + a[i][1];
    }
    for (loop = 1; loop <= )
    for (int i = 2; i <= n; i++)
    for (int j = 2; j <= n; j++)
    //for (int z = 0; z < 6; z++) {
        //int u = i - dx[z], v = j - dy[z];
    {   int tmp = int(1e9);
        //if (inRange(u, v)) tmp = min(tmp, f[u][v]);
        for (int u = max(i-3, 1); u <= min(i+3, n); u++)
        for (int v = max(j-3, 1); v <= min(j+3, n); v++)
        if (abs(i-u) + abs(j-v) == 1 || abs(i-u) + abs(j-v) == 3)
        tmp = min(tmp, f[u][v]);
        f[i][j] = tmp + 3*t + a[i][j];
    }

    cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << f[i][j] << " ";
        cout << endl;
    }

    int res = f[n][n];
    int x;
    for (int i = n-2; i <= n; i++)
    for (int j = n-2; j <= n; j++)
    if (x = abs(n-i) + abs(n-j) && x<= 2) res = min(res, f[i][j] + x*t);
    cout << res;
}
