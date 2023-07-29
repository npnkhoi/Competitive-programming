#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1005, M = 2e5 + 2;

vector<pair<int, int>> adj[N];
vector<int> ans, tmp_ans;
int n, m, val[N], pos[N], mark[N];
pair<int, int> e[M];

void dfs(int u) {
  for (auto v: adj[u]) {
    if (mark[v.first] == -1) {
      mark[v.first] = v.second;
      dfs(v.first);
    }
  }
}

void swaping(int a, int b) {
  swap(val[a], val[b]);
  pos[val[a]] = a;
  pos[val[b]] = b;
}

void tracing(int x) {
  // cerr << x << '\n';
  int eid = mark[x];
  if (eid == 0) return;
  
  pair<int, int> edge = e[eid];
  int nxt = (x == edge.first ? edge.second : edge.first);
  tracing(nxt);
  tmp_ans.push_back(eid);
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> n;
  FOR(i, 1, n) {
    cin >> val[i];
    pos[val[i]] = i;
  }
  cin >> m;
  FOR(i, 1, m) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back({b, i});
    adj[b].push_back({a, i});
    e[i] = {a, b};
  }
  FOR(i, 1, n) {
    if (pos[i] != i) {
      memset(mark, -1, sizeof mark);
      mark[pos[i]] = 0;
      dfs(pos[i]);

      if (mark[i] == -1) {
        cout << -1;
        return 0;
      } else {
        tmp_ans.clear();
        tracing(i);
        FOR(i, 0, tmp_ans.size() - 1) {
          swaping(e[tmp_ans[i]].first, e[tmp_ans[i]].second);
          ans.push_back(tmp_ans[i]);
        }
        FORD(i, tmp_ans.size() - 2, 0) {
          swaping(e[tmp_ans[i]].first, e[tmp_ans[i]].second);
          ans.push_back(tmp_ans[i]);
        }
      }
    }
  }
  cout << ans.size() << '\n';
  for (int v : ans) cout << v << ' '; cout << '\n';
  // FOR(i, 1, n) cerr << val[i] << ' '; cerr << endl;
}