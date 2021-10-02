#include <bits/stdc++.h>
using namespace std;

const int N = 5005, md = 998244353;

pair<int, int> a[N];
int f[N][N], g[N];

int main() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++ i) cin >> a[i].first;
  for (int i = 1; i <= n; ++ i) cin >> a[i].second;
  
  sort(a + 1, a + n + 1);
  a[0] = {0, 0};
  f[0][0] = 1;
  g[0] = 1;

  int res = 0;

  for (int i = 1; i <= n; ++ i) {
    for (int j = a[n].first; j >= a[i].second; -- j) {
      f[i][j] = g[j - a[i].second];
      if (j <= a[i].first) res = (res + f[i][j]) % md;
      g[j] = (g[j] + f[i][j]) % md;
    }
  }
  cout << res;
}