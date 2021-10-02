#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

pair<int, int> a[N];
set<pair<int, int>> points;

bool exist(pair<int, int> p) {
  return (points.find(p) != points.end());
}

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int n; cin >> n;
  for (int i = 0; i < n; ++ i) {
    cin >> a[i].first >> a[i].second;
    points.insert(a[i]);
  }

  int res = 0;
  for (int i = 0; i < n; ++ i) {
    for (int j = i + 1; j < n; ++ j) {
      // cerr << "visiting " << i << ' ' << j << '\n'; 
      if (a[i].first != a[j].first && a[i].second != a[j].second) {
        // cerr << "checking " << i << ' ' << j << '\n'; 
        if (exist({a[i].first, a[j].second}) && exist({a[j].first, a[i].second})) {
          // cerr << i << ' ' << j << '\n';
          res ++;
        }
      }
    }
  }
  cout << res / 2;
}