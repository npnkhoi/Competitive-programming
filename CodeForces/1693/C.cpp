#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int INF = 1e6, N = 2e5 + 5;

queue<int> q;
vector<int> adj[N];
set<int> adj_rev[N];
bool waiting[N];
int f[N];
int m, n;

void wait(int v) {
  if (!waiting[v]) {
    q.push(v);
    waiting[v] = true;
  }
}

int get_waiter() {
  if (q.empty()) return -1;
  int u = q.front(); q.pop();
  waiting[u] = false;
  return u;
}

int calculate(int v) {
  // must be O(MlogM or M)
  vector<pair<int, int>> cand;
  int num_cand = adj[v].size();
  for (int nei : adj[v]) {
    cand.push_back({f[nei], nei});
  }
  sort(cand.begin(), cand.end());
  int best = INF;
  FOR(i, 0, num_cand - 1) {
    best = min(best, (num_cand - i) + f[cand[i].second]);
  }
  return best;
}

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  FOR(i, 1, m) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj_rev[v].insert(u);
  }
  FOR(i, 1, n-1) f[i] = INF;
  for (auto v : adj_rev[n]) wait(v);

  while (!q.empty()) {
    int v = get_waiter();
    int best = calculate(v);
    if (best < f[v]) {
      f[v] = best;
      for (auto par : adj_rev[v]) {
        wait(par);
      }
    }
  }
  cout << f[1];
}