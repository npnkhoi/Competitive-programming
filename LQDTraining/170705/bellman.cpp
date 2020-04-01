using namespace std;
#include <stdio.h>
#include <iostream>
const int N = 2e3 + 50;
const int M = 2e4 + 50;
struct edge { int u, v, c; };
int n, m, s, f;
edge e[M];
int d[N], par[N];

void resOut(int u) {
    if (u != par[u]) resOut(par[u]);
    printf("%d ",u);
}
int main() {
    freopen("bellman.inp", "r", stdin);
    freopen("bellman.out", "w", stdout);
    scanf("%d %d %d %d", &n, &m, &s, &f);
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].c);
    for (int i = 1; i <= n; i++) d[i] = (int) 1e9;
    d[s] = 0; par[s] = s;

    for (int i = 1; i <= n-1; i++)
    for (int j = 1; j <= m; j++) {
        int x = e[j].u, y = e[j].v, w = e[j].c;
        if (d[y] > d[x] + w) {
            d[y] = d[x] + w;
            par[y] = x;
            //cout << d[y] << endl;
        }
    }
    for (int j = 1; j <= m; j++) {
        int x = e[j].u, y = e[j].v, w = e[j].c;
        if (d[y] > d[x] + w) {
            cout << "NO";
            return 0;
        }
    }
    cout << d[f] << "\n";
    resOut(f);
}
