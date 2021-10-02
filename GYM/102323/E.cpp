#include <bits/stdc++.h>
using namespace std;

const int N = 55;

string name[N];
vector<int> adj[N], scc[N], ans;
int num[N], low[N], mark[N], timer, idx;
stack<int> st;

void dfs1(int u) {
  mark[u] = 1;
  st.push(u);
  num[u] = low[u] = ++timer;

  for (int v : adj[u]) {
    if (num[v] == 0) {
      dfs1(v);
      low[u] = min(low[u], low[v]);
    } else if (mark[v] == 1) {
      low[u] = min(low[u], num[v]);
    }
  }

  if (num[u] == low[u]) {
    idx ++;
    while (true) {
      int vtx = st.top();
      scc[idx].push_back(st.top());
      st.pop();
      mark[vtx] = 2;
      if (vtx == u) break;
    }
  }
}

void dfs2(int u) {
  mark[u] = 1;
  ans.push_back(u);
  for (int v : adj[u]) {
    if (!mark[v]) dfs2(v);
  }
}



int main() {
  freopen("E.inp", "r", stdin);
  freopen("E.out", "w", stdout);
  int tc; cin >> tc;
  for (int itest = 1; itest <= tc; ++ itest) {
    
    // Reset
    memset(mark, 0, sizeof mark);
    memset(num, 0, sizeof num);
    memset(low, 0, sizeof low);
    ans.clear();
    for (int i = 1; i <= idx; ++ i) {
      scc[i].clear();
    }
    idx = timer = 0;

    // Read input
    int n, s; cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
      cin >> name[i];
      adj[i].clear();
    }
    for (int i = 1; i <= n; ++ i) {
      int x, j; cin >> x;
      while (x --) {
        cin >> j;
        adj[i].push_back(j);
      }
    }

    // Process
    dfs1(s);
    // for (int i = 1; i <= n; ++ i) {
    //   cerr << num[i] << ' ' << low[i] << '\n';
    // }

    // Output
    memset(mark, 0, sizeof mark);
    for (int i = 1; i <= idx; ++ i) {
      if (scc[i].size() > 1) {
        for (int x : scc[i]) {
          if (!mark[x]) dfs2(x);
        }
      }
    }
    sort(ans.begin(), ans.end());

    cout << "Chain Email #" << itest << ":\n";
    if (ans.empty()) {
      cout << "Safe chain email!\n";
    } else {
      for (auto id : ans) cout << name[id] << ' ';
      cout << '\n';
    }
    if (itest < tc) cout << '\n';
  }
}