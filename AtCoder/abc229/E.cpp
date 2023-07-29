#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 2e5 + 2;

int n, m, cc, dsu[N], cnt[N];
vector<int> adj[N];

int root(int u) {
  if (dsu[u] < 0) return u;
  else return dsu[u] = root(dsu[u]);
}

void merge(int u, int v) {
  u = root(u); v = root(v);
  if (u == v) return;
  if (dsu[u] > dsu[v]) swap(u, v);
  dsu[u] --;
  dsu[v] = u;
  cc --;
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> n >> m;
  memset(dsu, -1, sizeof dsu);
  FOR(i, 1, m) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  FORD(u, n, 1) {
    cc ++;
    for (int v : adj[u]) {
      if (v > u) merge(u, v);
    }
    cnt[u] = cc;
  }
  FOR(i, 2, n + 1) {
    cout << cnt[i] << '\n';
  }
}