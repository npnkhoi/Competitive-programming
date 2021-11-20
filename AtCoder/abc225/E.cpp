#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> Pack;

const int N = 2e5 + 5;

Pack a[N];

bool leftRight(Pack a, Pack b) {
  return a.second * b.first > b.second * a.first;
}

bool sort_cmp(Pack a, Pack b) {
  return leftRight({a.first, a.second-1}, {b.first, b.second-1});
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++ i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a+n, sort_cmp);
  int res = 0;
  Pack outerRight = {0, 1};
  for (int i = 0; i < n; ++ i) {
    if (!leftRight({a[i].first-1, a[i].second}, outerRight)) {
      res ++;
      outerRight = {a[i].first, a[i].second-1};
    }
  }
  cout << res;
}