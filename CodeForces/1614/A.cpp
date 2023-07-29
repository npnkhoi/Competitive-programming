#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int n, l, r, k, a[105];

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> l >> r >> k;
    FOR(i, 0, n-1) {
      cin >> a[i];
    }
    sort(a, a+n);
    int cnt = 0;
    FOR(i, 0, n-1) {
      if (l <= a[i] && a[i] <= r && a[i] <= k) {
        k -= a[i];
        cnt ++;
      }
    }
    cout << cnt << '\n';
  }
}