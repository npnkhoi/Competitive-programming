using namespace std;
#include <stdio.h>
#include <vector>

const int K = 1e5 + 10;
const int N = 55;
const int md = 2017;
int n, m, k;
vector<int> adj[N];
int f[K][N];
int main () {
    freopen("cpath.inp", "r", stdin);
    freopen("cpath.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    f[0][1] = 1;
    for (int i = 0; i < k; i++)
    for (int j = 1; j <= n; j++)
        if (f[i][j])
        for (int k = 0; k < adj[j].size(); k++) {
            int v = adj[j][k];
            f[i+1][v] = (f[i+1][v] + f[i][j]) % md;
        }
    printf("%d", f[k][n]);
}
