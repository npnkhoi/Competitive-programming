#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef pair<int, pair<int, int>> Edge;

vector<Edge> e;
int up[N];

int root(int u) {
  if (up[u] < 0) return u;
  else {
    up[u] = root(up[u]);
    return up[u];
  }
}

bool unite(int a, int b) {
  a = root(a);
  b = root(b);
  if (a == b) return false;
  if (up[a] > up[b]) swap(a, b);
  up[b] = a;
  up[a] --;
  return true;
}

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);

  memset(up, -1, sizeof up);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++ i) {
    int a, b, c;
    cin >> a >> b >> c;
    e.push_back({c, {a, b}});
  }
  sort(e.begin(), e.end());

  long long res = 0;
  for (auto edge : e) {
    if (!unite(edge.second.first, edge.second.second)) {
      if (edge.first > 0) {
        res += edge.first;
      }
    }
  }
  cout << res;
}