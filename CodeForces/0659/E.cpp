using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>

const int N = 1e5 + 50;
vector<int> adj[N];
vector<int> dsu (N, 0);
int n, m, cnt, res;
bool isTree;
int cc, cntV, cntE;

void dfs(int u, int d) {
    dsu[u] = d; cntV ++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (dsu[v] == 0 || dsu[v] == d) cntE ++;
        if (dsu[v] == 0) dfs(v, d);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cc = 0;

    for (int i = 1; i <= n; i++)
        if (!dsu[i]) {
            cntE = cntV = 0;
            dfs(i, ++cc);
            res += (cntE == 2*(cntV - 1));
            //cout << i << " " << cntE << " " << cntV << endl;
        }
    cout << res;
}
