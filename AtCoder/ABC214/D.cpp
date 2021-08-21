#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

typedef pair<int, pair<int, int> > Edge;

int n, up[N];
vector<Edge> edge;

int getRoot(int u) {
  if (up[u] < 0) {
    return u;
  }
  up[u] = getRoot(up[u]);
  return up[u];
}


void unite(int u, int v) {
  u = getRoot(u);
  v = getRoot(v);
  
  if (up[u] > up[v]) {
    swap(u, v);
  }
  up[u] += up[v];
  up[v] = u;
}

int main() {
  cin >> n;
  for (int i = 0; i < n-1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.push_back({w, {u, v}});
  }
  sort(edge.begin(), edge.end());
  memset(up, -1, sizeof up);

  long long res = 0;
  for (Edge e : edge) {
    res += 1LL * e.first * up[getRoot(e.second.first)] * up[getRoot(e.second.second)];
    unite(e.second.first, e.second.second);
  }  
  cout << res;
}