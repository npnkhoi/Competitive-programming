#include <bits/stdc++.h>
using namespace std;

const int md = 7901, N = 1005;

int a[N], fac[N];

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  
  fac[0] = 1;
  for (int i = 1; i <= 1000; ++ i) fac[i] = fac[i-1] * i % md;

  int tc; cin >> tc;
  while (tc --) {
    int n; cin >> n;
    for (int i = 0; i < n; ++ i) {
      cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 0, res = 1;
    for (int i = 0; i < n; ++ i) {
      cnt ++;
      if (i == n - 1 || a[i] != a[i+1]) {
        res = res * fac[cnt] % md;
        cnt = 0;
      }
    }
    cout << res << '\n';
  }
}