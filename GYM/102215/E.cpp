#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

pair<pair<int, int>, int> a[N];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++ i) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i + 1;
  }
  sort(a, a+n);
  int last = 0, i = 0;
  vector<int> ans;
  while (i < n && last < m) {
    int best = -1;
    while (i < n && a[i].first.first <= last + 1) {
      if (a[i].first.second > last) {
        if (best == -1 || a[i].first.second > a[best].first.second) {
          best = i;
        }
      }
      i ++;
    }
    // cerr << best << ' ' << i << '\n';
    if (best == -1) break;
    ans.push_back(a[best].second);
    last = a[best].first.second;
  }
  if (last == m) {
    cout << "YES\n" << ans.size() << '\n';
    for (int x : ans) {
      cout << x << ' ';
    }
  } else {
    cout << "NO\n";
  }
}