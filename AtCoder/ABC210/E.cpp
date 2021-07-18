#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
pair<int, int> a[N];

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++ i) {
    cin >> a[i].second >> a[i].first;
  }
  int cc = 0;
  long long res = 0;
  sort(a, a + m);
  for (int i = 0; i < m; ++ i) {
    int new_cc = __gcd(cc, __gcd(a[i].second, n - a[i].second));
    res += 1LL * ((cc == 0 ? n : cc) - new_cc) * a[i].first;
    // cerr << new_cc << ' ' << res << '\n';
    cc = new_cc;
    if (cc == 1) {
      break;
    }
  }
  if (cc != 1) {
    cout << -1;
  } else {
    cout << res;
  }
}