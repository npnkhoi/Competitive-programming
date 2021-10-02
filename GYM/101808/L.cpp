#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];

void dfs(int u) {

} 

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int tc; cin >> tc;
  while (tc --) {
    cin >> n;
    for (int i = 1; i <= n; ++ i) adj[i].clear();
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) {
      cin >> j;
      if (j > 0) adj[j].push_back(i);
    }
    dfs(1);
  }
}