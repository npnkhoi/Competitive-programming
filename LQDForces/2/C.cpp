#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int tc, n, a[N], mark[N];
string s, t;

bool check(int x) {
  //cerr << "check " << x << "\n";
  memset(mark, 0, sizeof mark);
  for (int i = 1; i <= x; ++ i) {
    mark[a[i] - 1] = 1;
  }
  for (int i = 0, j = 0; i < t.size(); ++ i, ++ j) {
    while (j < s.size() && (t[i] != s[j] || mark[j])) ++ j;
    if (j >= s.size() || t[i] != s[j]) return false;
    //cerr << i << " " << j << "\n";
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> tc;
  while (tc --) {
    cin >> s >> t;
    n = s.size();
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int l = 0, r = n, mid, bs = l;
    while (l <= r) {
      mid = (l + r) / 2;
      if (check(mid)) {
        bs = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << bs << "\n";
  }
}
