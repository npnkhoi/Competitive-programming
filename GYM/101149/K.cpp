#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int x, y, u, v;
  cin >> x >> y >> u >> v;
  double r = sqrt((x - u) * (x - u) + (y - v) * (y - v)) / 2;
  double s = r * r * M_PI;
  cout << fixed << setprecision(10);
  cout << s;
}