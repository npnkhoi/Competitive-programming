#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  long long n, res = 0;
  cin >> n;
  for (long long a = 1; a * a * a <= n; ++ a) {
    long long rest = n / a;
    for (long long b = a; b * b <= rest; ++ b) {
      res += rest / b - b + 1;
    }
  }
  cout << res;
}