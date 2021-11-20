#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int tc; cin >> tc;
  while (tc --) {
    int n, res; 
    cin >> n;
    res = n;
    for (int i = 1; i <= n-1; ++ i) {
      int x; cin >> x;
      if (x != i && res == n) {
        res = i;
      }
    }
    cout << res << '\n';
  }
}