#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int n, x, m;
  string s, t;
  cin >> n >> x >> s >> m >> t;
  int pos = x - 1;
  cout << s[pos];
  for (int i = 0 ; i < m; ++ i) {
    pos += (t[i] == 'R' ? +1 : -1);
    cout << s[pos];
  }
}