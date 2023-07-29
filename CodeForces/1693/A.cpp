#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int tc, n, x;
  cin >> tc;
  while (tc --) {
    cin >> n;
    long long s = 0;
    bool ans = true;
    bool zero = false;
    FOR(i, 1, n) {
      cin >> x;
      if (zero && x != 0) ans = false; 
      s += x;
      if (s < 0) ans = false;
      if (s == 0) {
        zero = true;
      }
    }
    ans &= zero;
    cout << (ans ? "Yes" : "No") << '\n';
  }
}