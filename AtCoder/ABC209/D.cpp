#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout, depth;
vector<vector<int>> up;

void dfs(int v, int p, int dep)
{
    tin[v] = ++timer;
    up[v][0] = p;
    depth[v] = dep;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, dep + 1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root, 0);
}

int main() {
  int q;
  cin >> n >> q;
  adj.resize(n);
  for (int i = 0; i < n-1; ++ i) {
    int a, b;
    cin >> a >> b;
    a --; b --;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  preprocess(0);

  while (q --) {
    int c, d;
    cin >> c >> d;
    c --; d --;
    int anc = lca(c, d);
    int dist = depth[c] + depth[d] - 2 * depth[anc];
    cout << (dist % 2 == 0 ? "Town" : "Road") << '\n';;
  }
}