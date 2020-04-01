#include <bits/stdc++.h>
using namespace std;

const int N = 1212 + 5;

int n, m, q, k, tc, f[N][N];

void init() {
  for (int i = 1; i <= n; ++ i) {
    f[i][0] = f[i][i] = 1;
    for (int j = 1; j < i; ++ j) {
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % m;
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> tc;
  while (tc --) {
    cin >> n >> m >> q;
    init();
    while (q --) {
      cin >> k;
      cout << f[n][k] << "\n";
    }
  }
}
