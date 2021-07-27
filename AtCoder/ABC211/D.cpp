#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, MOD = 1e9+7;

int n, m, a, b, dp[N], dist[N];
vector<int> adj[N];
queue<int> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++ i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 2; i <= n; ++ i) {
        dist[i] = MOD;
    }
    q.push(1);
    dp[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            int newDist = dist[u] + 1;
            if (newDist == dist[v]) {
                dp[v] = (dp[v] + dp[u]) % MOD;
            } else if (newDist < dist[v]) {
                dist[v] = newDist;
                dp[v] = dp[u];
                q.push(v);
            }
        }
    }
    cout << dp[n];
}