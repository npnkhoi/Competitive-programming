#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long mul(long long a, long long n, long long md) {
  if (n == 0) return 0;
  long long tmp = mul(a, n/2, md);
  tmp = (tmp + tmp) % md;
  if (n % 2) tmp = (tmp + a) % md;
  return tmp;
}

long long expo(long long a, long long n, long long md) {
  if (n == 0) return 1;
  long long tmp = expo(a, n/2, md);
  tmp = mul(tmp, tmp, md);
  if (n % 2) tmp = mul(tmp, a, md);
  tmp %= md;
  return tmp;
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  long long n, k, m;
  cin >> n >> k >> m;
  if (m % MOD == 0) {
    cout << 0;
    return 0;
  }
  long long tmp = expo(k, n, MOD-1);
  tmp = expo(m, tmp, MOD);
  cout << tmp;
}