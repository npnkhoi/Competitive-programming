#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, vis[N];
vector<int> adj[N];

void dfs(int u) {
    vis[u] = 1;
    cout << u << ' ';
    sort(adj[u].begin(), adj[u].end());
    // int cnt = 0;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
            // cnt ++;
            cout << u << ' ';
        }
    }
    // if (!leaf) {
    // }
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; ++ i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
}