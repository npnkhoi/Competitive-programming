#include <bits/stdc++.h>
using namespace std;

const int N = 1030, MOD = 998244353;

int f[N][N], g[11][N], h[N];

int main() {
  int n; string s;
  cin >> n >> s;
  f[0][0] = 1;
  h[0] = 1;
  for (int i = 1; i <= n; ++ i) {
    int id = s[i - 1] - 'A';

    for (int mask = 0; mask < (1 << 10); ++ mask) {
      int mini_mask = mask ^ (1 << id);
      if (mini_mask > mask) continue;
      f[i][mask] = ((g[id][mask] + h[mini_mask]) % MOD - g[id][mini_mask] + MOD) % MOD;
      // if (f[i][mask] != 0) {
      //   printf("f(%d, %d) = %d\n", i, mask, f[i][mask]);
      // }
    }
    for (int mask = 0; mask < (1 << 10); ++ mask) {
      g[id][mask] = (g[id][mask] + f[i][mask]) % MOD;
      h[mask] = (h[mask] + f[i][mask]) % MOD;
    }
  }
  // cerr << "ok\n";
  int res = 0;
  for (int mask = 1; mask < (1 << 10); ++ mask) {
    res = (res + h[mask]) % MOD;
  }
  cout << res;
}