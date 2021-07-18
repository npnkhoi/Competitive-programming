#include <bits/stdc++.h>
using namespace std;

int fac[20];

int main() {
  int p;
  cin >> p;
  fac[0] = 1;
  int lim = 0;
  for (int i = 1; i <= 19; ++ i) {
    fac[i] = fac[i - 1] * i;
    if (fac[i] > p) {
      lim = i - 1;
      break;
    }
  }
  // cerr << "lim = " << lim << '\n';
  int res = 0;
  for (int i = lim; i >= 1; -- i) {
    res += p / fac[i];
    p = p % fac[i];
  }
  cout << res;
}