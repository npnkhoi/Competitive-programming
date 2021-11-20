#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int tc; cin >> tc;
  while (tc--) {
    long long k, p, n;
    cin >> k >> p >> n;
    cout << max(0LL, k-p) * n << '\n';
  }

}