#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

double eval(double a, double b, double c, double x) {
  return a * x * x + b * x + c;
}

double getMax(double a, double b, double c, double l, double r) {
  double peak = - b / (2 * a);
  if (l <= peak && peak <= r) {
    return eval(a, b, c, peak);
  } else if (peak < l) {
    return eval(a, b, c, l);
  } else {
    return eval(a, b, c, r); 
  }
}

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  double A, h;
  cin >> A >> h;

  double res = 0;

  // First range
  double a = -6*A/h, b = 6*A, c = 0;
  res = max(res, getMax(a, b, c, 0, h/6));

  // Second range
  a = -6*(100-A)/h, b = 6*(100-A) - (2*A-100), c = (2*A-100)*h;
  res = max(res, getMax(a, b, c, h/6, h/3));

  cout << fixed << setprecision(10);
  cout << res;
}