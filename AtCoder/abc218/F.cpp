#include <bits/stdc++.h>
using namespace std;

const int N = 405;

int dist[N], mark[N*N];
pair<int, int> trace[N];
vector<pair<int, int>> adj[N];

void bfs(int ban) {
  memset(dist, -1, sizeof dist);
  dist[1] = 0;
  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto e : adj[u]) {
      if (e.second != ban && dist[e.first] == -1) {
        dist[e.first] = dist[u] + 1;
        trace[e.first] = {u, e.second};
        q.push(e.first);
      }
    }
  }
}

void tracing(int u) {
  // cerr << "tracing " << u << '\n';
  if (trace[u].first == 0) {
    return;
  }
  mark[trace[u].second] = 1;
  tracing(trace[u].first);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++ i) {
    int s, t;
    cin >> s >> t;
    adj[s].push_back({t, i});
  }
  // cerr << "hello\n";
  bfs(0);
  // cerr << "hello\n";
  int tmp = dist[n];
  tracing(n);
  // cerr << "hello\n";

  for (int i = 1; i <= m; ++ i) {
    if (mark[i]) {
      bfs(i);
      cout << dist[n] << '\n';
    } else {
      // cerr << "pruning :3\n";
      cout << tmp << '\n';
    }
  }
} 