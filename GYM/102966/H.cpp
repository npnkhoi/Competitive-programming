#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, LIM = 1e5 + 2;

long long f[LIM];

long long Exp(int a, int n) {
  if (n == 0) return 1;
  long long res = Exp(a, n / 2);
  res = res * res % MOD;
  if (n % 2) res = res * a % MOD;
  return res;
}

void init() {
  f[1] = 1;
  for (int i = 1; i <= LIM - 2; ++ i) {
    f[i + 1] = f[i] * 2 % MOD * (2 * i + 1) % MOD * Exp(i + 1, MOD - 2) % MOD;
  }
}

int main() {
  int tc; cin >> tc;
  init();
  while (tc --) {
    int n; cin >> n;
    cout << f[n] << '\n';
  }
} 