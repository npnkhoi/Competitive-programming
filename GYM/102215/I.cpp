#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int a, b;
  cin >> a >> b;
  long long res = a - b;
  int x = a, y = a - b;
  while (x > 0 && y > 0) {
    res += y;
    x -= b;
    swap(x, y);
  }
  cout << res;
}