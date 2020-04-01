using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
const int N = 5e4 + 50;
const int K = 500 + 50;
int n, k;
vector<int> adj[N], son[N];
bool sign[N];
int f[N][K];
long long res;
void dfs(int u) {
    if (sign[u]) return;
    //printf("dfs %d:\n",u);
    sign[u] = 1; f[u][0] = 1;
    for (int i = 0; i < adj[u].size(); i++)
    if (!sign[adj[u][i]]) {
        int v = adj[u][i];
        son[u].push_back(v);
        dfs(v);
        for (int j = 1; j <= k; j++)
        f[u][j] += f[v][j-1];
    }
}
int main() {
    //freopen("test.inp","r",stdin);
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n ; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        //cout << u << " " << v << endl;
    }
    //cout << "------------\n";
    dfs(1);
    /*cout << "------------\n";
    for (int i = 1; i <= n; i++) {
        //cerr << i << ": ";
        for (int j = 0; j < son[i].size(); j++)
        cout << son[i][j] << " " ;
        cout << endl;

    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) cout << f[i][j] << " " ;
        cout << endl;
    }*/
    for (int u = 1; u <= n; u++) {
        res += f[u][k];

        long long tmp = 0;
        for (int x = 1; x < k; x++)
        for (int i = 0; i < son[u].size(); i++) {
            int v = son[u][i];
            tmp += 1LL * (f[u][x] - f[v][x-1]) * f[v][k-x-1];
        }
        res += tmp / 2;
        //cerr << res << " " << tmp << endl;
    }
    cout << res;
}
