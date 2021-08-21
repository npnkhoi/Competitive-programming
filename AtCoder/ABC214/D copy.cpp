#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, vis[N], sz[N], maxEdge[N];
vector<pair<int, int>> adj[N];
pair<int, int> up[N];

void dfs(int u) {
  vis[u] = 1;
  sz[u] = 1;
  for (auto edge : adj[u]) {
    int v = edge.first, w = edge.second;
    if (!vis[v]) {
      dfs(v);
      up[v] = {u, w};
      sz[u] += sz[v];
      maxEdge[u] = max(maxEdge[u], max(w, maxEdge[v]));
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dfs(1);

  long long res = 0;
  for (int u = 2; u <= n; ++ u) {
    int v = up[u].first, w = up[u].second;
    
    if (w >= maxEdge[u] && w >= maxEdge[1]) {
      res += 1LL * w * sz[u] * (n - sz[u]);
    }
  }

  cout << res;
}