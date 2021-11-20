#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 20) + 2;

long long a[N];
int dsu[N], n;

int root(int u) {
  if (dsu[u] < 0) return u;
  return dsu[u] = root(dsu[u]);
}

void unite(int u, int v) {
  // cerr << u << '\n';
  u = root(u);
  v = root(v);
  if (u == v) return;
  // if (dsu[v] < dsu[u]) swap(u, v);
  // dsu[v] += dsu[u];
  dsu[u] = v;
}

int crop(int val) {
  if (val >= n) val -= n;
  if (val < 0) val += n;
  return val;
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int q;
  cin >> q;
  n = (1 << 20);
  memset(a, -1, sizeof a);
  memset(dsu, -1, sizeof dsu);
  while (q--) {
    int t;
    long long x;
    cin >> t >> x;
    int h = x % n;

    if (t == 1) {
      if (a[h] != -1) h = crop(root(h) + 1);
      a[h] = x;
      // then what?
      int pre = crop(h-1);
      int nxt = crop(h+1);
      if (a[pre] != -1) {
        unite(pre, h);
      }
      if (a[nxt] != -1) {
        unite(h, nxt);
      }
    } else {
      cout << a[h] << '\n';
    }
  }
}