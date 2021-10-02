#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a, b;

vector<string> rotate(vector<string> &v) {
  vector<string> ret(n, "");
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      ret[i].push_back(v[j][n-i-1]);
    }
  }
  return ret;
}

vector<pair<int, int>> feature(vector<string> &v) {
  vector<pair<int, int>> ret;
  int x = -1, y = -1;
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      if (v[i][j] == '#') {
        if (x == -1) {
          x = i, y = j;
        } else {
          ret.push_back({i - x, j - y});
        }
      }
    }
  }
  // for (auto x : ret) {
  //   cerr << x.first << ' ' << x.second << "; ";
  // }
  // cerr << '\n';
  return ret;
}

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  cin >> n;
  a.resize(n);
  b.resize(n);

  for (int i = 0; i < n; ++ i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++ i) {
    cin >> b[i];
  }
  bool ans = false;
  for (int i = 0; i < 4; ++ i) {
    b = rotate(b);
    if (feature(a) == feature(b)) {
      ans = true;
    }
  }
  cout << (ans ? "Yes" : "No");
}