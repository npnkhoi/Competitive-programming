using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

const int N = 3e3 + 50;
int n, x = 0, y = 0;
vector<int> par(N, -1);
vector<int> d(N, -1);
vector<int> adj[N];
queue<int> q;
void dfs(int u) {
    //cout << u << "\n";
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        //cout << v << "\n";
        if (par[v] == -1) par[v] = u, dfs(v);
        else if (v != par[u] && x == 0 && y == 0) x = u, y = v;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1] = 0;
    dfs(1);
    /*cout << x << " " << y << endl;
    for (int i = 1; i <= n; i++) cout << par[i] << " ";
    cout << "\n";*/
    q.push(x), d[x] = 0;
    while (x != y) x = par[x], q.push(x), d[x] = 0;
    int cnt = 0;

    while (!q.empty()) {
        //cout << cnt << endl;
        cnt ++;
        int s = q.size();
        while (s--) {
            int u = q.front(); q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (d[v] == -1) q.push(v), d[v] = cnt;
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", d[i]);
}
