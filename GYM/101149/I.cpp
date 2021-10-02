#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
bool no_cop[N];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++ i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int hidden = 1;
  for (int i = 2; i <= n; ++ i) {
    if (adj[i].size() < adj[hidden].size()) {
      hidden = i;
    }
  }
  no_cop[hidden] = true;
  for (int v : adj[hidden]) {
    no_cop[v] = true;
  }
  for (int i = 1; i <= n; ++ i) {
    cout << (no_cop[i] ? 0 : 1) << " ";
  }
}