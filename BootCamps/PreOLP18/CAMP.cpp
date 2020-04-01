#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 205;
const int oo = 1e8 + 7;
int n, m, c[N][N], trace[N][N];
void printPath(int u, int v) {
    if (trace[u][v] == 0) printf(" -> %d", v);
    else {
        printPath(u, trace[u][v]);
        printPath(trace[u][v], v);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        if (i != j) c[i][j] = oo;

    for (int i = 1; i <= m; i++) {
        int u, v, c_;
        scanf("%d%d%d", &u, &v, &c_);
        c[u][v] = min(c[u][v], c_);
        c[v][u] = min(c[v][u], c_);
    }

    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    if (c[i][j] > c[i][k] + c[k][j]) {
        c[i][j] = c[i][k] + c[k][j];
        trace[i][j] = k;
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%10d", c[i][j]);
        cerr << "\n";
    }*/

    int minDist = oo, u, v;
    for (int i = 1; i <= n; i++) {
        int tmp = 1;
        for (int j = 2; j <= n; j++)
        if (c[i][j] > c[i][tmp]) tmp = j;
        if (c[i][tmp] < minDist) {
            minDist = c[i][tmp];
            u = i, v = tmp;
        }
    }
    printf("%d\n%d %d\n", u, v, minDist);
    printf("%d", u); printPath(u, v);
}
