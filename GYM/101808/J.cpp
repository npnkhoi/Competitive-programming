#include <bits/stdc++.h>
using namespace std;

int l[2], r[2], p[2], d[2], k;

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int tc; cin >> tc;
  while (tc --) {
    cin >> l[0] >> r[0] >> p[0] >> d[0];
    cin >> l[1] >> r[1] >> p[1] >> d[1];
    cin >> k;

    if (d[0] == 0) d[0] = -1;
    if (d[1] == 0) d[1] = -1;

    int res = 0;
    for (int i = 0; i <= k; ++ i) {
      res += (p[0] == p[1]);
      for (int j = 0; j < 2; ++ j) {
        p[j] += d[j];
        if (p[j] > r[j] || p[j] < l[j]) {
          d[j] = -d[j];
          p[j] += 2 * d[j];
        }
      }
    }
    cout << res << '\n';
  }
}