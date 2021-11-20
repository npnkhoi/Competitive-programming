#include <bits/stdc++.h>
using namespace std;

const int P = 22;

int connections[P];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int tc;
  cin >> tc;
  while (tc --) {
    // Init
    memset(connections, 0, sizeof connections);

    int p, n;
    cin >> p >> n;
    for (int i = 0; i < n; ++ i) {
      int b, g;
      cin >> b >> g;
      b --; g --;
      connections[b] |= (1 << g);
      // link[b][g] = 1;
    }

    int res = 0;
    for (int boySet = 0; boySet < (1 << p); ++ boySet) {
      int girlSet = (1 << p) - 1;
      for (int b = 0; b < p; ++ b) {
        if (boySet >> b & 1) { // the boy is chosen
          girlSet &= connections[b];
        }
      }
      res = max(res, __builtin_popcount(boySet) + __builtin_popcount(girlSet));      
    }
    cout << res << '\n';
  }
}