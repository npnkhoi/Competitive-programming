#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, INF = 1e9 + 7;

vector<int> adj[N];
int a[N], dp[N];
multiset<int> l, r;

void update(int val, int type) {
  // cerr << "updating " << val << ' ' << type << '\n';
  if (type == 1) {
    if (l.empty() || val <= *l.rbegin()) {
      l.insert(val);
    } else {
      r.insert(val);
    }
  } else {
    if (!l.empty() && val <= *l.rbegin()) {
      l.erase(l.find(val));
    } else {
      r.erase(r.find(val));
    }
  }
  // balance
  while (l.size() > r.size() + 1) {
    int x = *l.rbegin();
    l.erase(l.find(x));
    r.insert(x);
  }
  while (l.size() < r.size()) {
    int x = *r.begin();
    r.erase(r.find(x));
    l.insert(x);
  }
  // cerr << "result:\n";
  // for (auto it : l) cerr << it << ' '; cerr << '\n';
  // for (auto it : r) cerr << it << ' '; cerr << '\n';
}

int median() {
  // cerr << l.size() << ' ' << r.size() << '\n';
  if (l.size() == r.size()) {
    return ((*l.rbegin()) + (*r.begin())) / 2;
  } else {
    return *l.rbegin();
  }
}

void dfs(int u, int par, int turn) {
  // cerr << "dfs " << u << '\n';
  update(a[u], +1);

  dp[u] = (turn == 0 ? -INF : INF);
  bool leaf = true;
  for (int v : adj[u]) {
    if (v == par) continue;
    leaf = false;
    dfs(v, u, 1 - turn);
    if (turn == 0) {
      dp[u] = max(dp[u], dp[v]);
    } else {
      dp[u] = min(dp[u], dp[v]);
    }
  }
  if (leaf) dp[u] = median();
  // cerr << "dp " << u << " = " << dp[u] << '\n';
  update(a[u], -1);
}

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int n; cin >> n;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; ++ i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1, 0);
  // for (int i = 1; i <= n; ++ i) {
  //   cerr << dp[i] << ' ';
  // }
  // cerr << '\n';
  cout << dp[1];
}