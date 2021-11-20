#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int pre[N], nxt[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, q;
  cin >> n >> q; 
  while (q--) {
    int query, x, y;
    cin >> query;
    if (query == 1) {
      cin >> x >> y;
      pre[y] = x;
      nxt[x] = y;
    } else if (query == 2) {
      cin >> x >> y;
      pre[y] = 0;
      nxt[x] = 0;
    } else {
      cin >> x;
      while (pre[x] != 0) x = pre[x];
      vector<int> ans;
      while (true) {
        ans.push_back(x);
        if (nxt[x] == 0) break;
        x = nxt[x];
      }
      cout << ans.size() << ' ';
      for (int x : ans) cout << x << ' ';
      cout << '\n';
    }
  }
}