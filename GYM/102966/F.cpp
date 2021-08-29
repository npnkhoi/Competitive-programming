#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long Exp(int a, int n) {
  if (n == 0) return 1;
  long long res = Exp(a, n / 2);
  res = res * res % MOD;
  if (n % 2) res = res * a % MOD;
  return res;
}

int main() {
  freopen("F.inp", "r", stdin);
  freopen("F.out", "w", stdout);
  long long n;
  while (cin >> n) {
    n = n % MOD;
    
    long long f3_a = (Exp(n, 2) * (n - 1) % MOD * Exp(2, MOD - 2) % MOD - n * (n - 1) % MOD * (2 * n - 1) % MOD * Exp(6, MOD - 2) % MOD) * Exp(n, 2) % MOD * 2 % MOD;
    // long long f3_b = (Exp(n, 3) + Exp(n, 5)) % MOD * Exp(2, MOD - 2) % MOD;
    long long f3_b = Exp(n, 5);
    long long f3 = (f3_a + f3_b) % MOD; // mid to side
    // long long f3 = (17 * Exp(n, 5) - 11 * Exp(n, 3)) % MOD * Exp(6, MOD - 2) % MOD; // mid to side

    long long f2 = (f3 + Exp(n, 5)) % MOD; // opposite - CORRECT
    long long f1 = 2 * Exp(n, 5) % MOD; // adjacent
    long long f4 = f3_a * 5 % MOD;
    long long res = (4 * f1 + 2 * f2 + 4 * f3 + f4) % MOD;
    if (res < 0) res += MOD;
    cerr << f1 << ' ' << f2 << ' ' << f3 << ' ' << f4 << '\n';
    cout << res << '\n';
  }
}