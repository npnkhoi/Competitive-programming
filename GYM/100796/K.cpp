#include <bits/stdc++.h>
using namespace std;

bool profact(long long x) {
  int pre = 1e9;
  for (int i = 2; x != 1; ++i) {
    if (x % i != 0) return false;
    int cnt = 0;
    while (x % i == 0) {
      x /= i;
      cnt ++;
    }
    if (cnt > pre) return false;
    pre = cnt;
  }
  return true;
}

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int tc; cin >> tc;
  while (tc --) {
    long long a;
    cin >> a;
    cout << (profact(a) ? "YES\n" : "NO\n");
  }
}