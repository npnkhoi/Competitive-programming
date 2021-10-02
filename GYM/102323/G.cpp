#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int memo[N][2*N][3*N][2];

int f(int a, int b, int c, int t) {
  // cerr << a << ' ' << b << ' ' << c << ' ' << t << '\n';
  if (memo[a][b][c][t] != -1) {
    return memo[a][b][c][t];
    // cerr << "returning immediately\n";
  }

  int ret = -1;
  if ((a == 0) && (b == 0)) {
    ret = 0;
    // cerr << "end!\n";
  } else if (t && (b > 0) && (b % 2 == 0)) {
    ret = f(a, b-1, c+1, t);
  } else if (t && (b == 0) && (a > 0)) {
    ret = f(a-1, b+1, c, t);
  } else if (b%2 && (t == 0)) {
    ret = f(a, b, c, 1);
  } else if (a > 0 && (b == 0) && c && (t==0)) {
    ret = f(a-1, b, c, 1);
  } else if ((b == 1) && c && (t==0)) {
    ret = f(a, b, c, 1);
  } else {
    ret = -1;
    if (a > 0) {
      // cerr << "calling " << a-1 << ' ' << b+1 << ' ' << c << ' ' << t << '\n';
      ret = max(ret, f(a-1, b+1, c, t) + 1);
    }
    if (b > 0) {
      // cerr << "calling " << a << ' ' << b-1 << ' ' << c+1 << ' ' << t << '\n';
      ret = max(ret, f(a, b-1, c+1, t) + 1);
    }
  }
  memo[a][b][c][t] = ret;
  // cerr << "f of " << a << ' ' << b << ' ' << c << ' ' << t << " = " << ret << '\n';
  return ret;
}

int main() {
  freopen("G.inp", "r", stdin);
  freopen("G.out", "w", stdout);

  memset(memo, -1, sizeof memo);
  int tc; cin >> tc;
  
  for (int itest = 1; itest <= tc; ++itest) {
    int a, b, c; 
    cin >> a >> b >> c;
    // cerr << "input: " << a << ' ' << b << ' ' << c << '\n';
    cout << "Scenario #" << itest << ": " << f(a, b, c, 0);
    if (itest < tc) cout << '\n';
  }
}