#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m;
bool vis[N];
vector<int> adj[N];

void dfs(int v) {
  vis[v] = true;
  for (int u : adj[v]) {
    if (!vis[u]) {
      dfs(u);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0 ; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  vector<int> ans;
  for (int i = 1; i <= n; ++ i) {
    if (!vis[i]) {
      ans.push_back(i);
    }
  }
  if (ans.empty()) {
    cout << "Connected";
  } else {
    for (int v : ans) {
      cout << v << '\n';
    }
  }
}