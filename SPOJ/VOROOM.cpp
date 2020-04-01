#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 2e5 + 5;
long long cntV, cntE, x;
bool vis[N];
vector<int> adj[N];
void dfs(int u) {
    cntE += adj[u].size();
    cntV ++;
    vis[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (vis[v] == 0) dfs(v);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    REP(i, n) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i, 1, n+1) if (vis[i] == 0) {
        cntV = cntE = 0;
        dfs(i);
        cntE /= 2;
        if (cntV < cntE) {cout << "0"; return 0;}
        if (cntE == cntV - 1) x = cntV;
    }
    cout << x * (x-1) / 2 + x * (n+1-x);
}
