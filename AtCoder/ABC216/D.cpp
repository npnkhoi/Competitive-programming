#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N], a[N];
int vis[N];
bool ok;

void dfs(int u) {
  vis[u] = 1;
  for (int v : adj[u]) {
    if (vis[v] == 0) dfs(v);
    else if (vis[v] == 1) {
      ok = false;
    }
  }
  vis[u] = 2;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++ i) {
    int k; cin >> k;
    for (int j = 0; j < k; ++j) {
      int x; cin >> x;
      a[i].push_back(x);
      if (j > 0) {
        adj[a[i][j]].push_back(a[i][j-1]);
      }
    }
  }

  ok = true;
  for (int i = 1; i <= n; ++ i) {
    if (vis[i] == 0) {
      dfs(i);
    }
  }
  cout << (ok ? "Yes" : "No");
}