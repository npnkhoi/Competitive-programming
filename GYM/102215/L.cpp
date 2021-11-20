#include <bits/stdc++.h>
using namespace std;

#define sqr(x) (x)*(x)

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  long long x1, x2, y1, y2, r1, r2;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;
  double long dist = sqrt(sqr(x1 - x2) + sqr(y1-y2));
  double r = (r1 + r2 - dist) / 2;
  double o1o3 = r1 - r;
  // o1o3 / dist = (x1 - x3) / (x1 - x2)
  double x3 = (x1 == x2 ? x1 : x1 - o1o3 * (x1 - x2) / dist);
  double y3 = (y1 == y2 ? y1 : y1 - o1o3 * (y1 - y2) / dist);
  cout << fixed << setprecision(15);
  cout << x3 << ' ' << y3 << ' ' << r;
}