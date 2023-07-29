#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 5005;

string a[N];
int l[N][N], r[N][N], u[N][N], d[N][N];

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int m, n;
  cin >> m >> n;
  FOR(i, 0, m-1) cin >> a[i];

  FOR(i, 0, m-1) {
    l[i][0] = (a[i][0] == '0' ? -1 : 0);
    FOR(j, 1, n-1) {
      l[i][j] = (
        a[i][j] == '0' ? -1 : (
          l[i][j-1] == -1 ? j : l[i][j-1]
        )
      );
    }

    r[i][n-1] = (a[i][n-1] == '0' ? -1 : n-1);
    FORD(j, n-2, 0) {
      r[i][j] = (
        a[i][j] == '0' ? -1 : (
          r[i][j+1] == -1 ? j : r[i][j+1]
        )
      );
    }
  }

  FOR(j, 0, n-1) {
    u[0][j] = (a[0][j] == '0' ? -1 : 0);
    FOR(i, 1, m-1) {
      u[i][j] = (
        a[i][j] == '0' ? -1 : (
          u[i-1][j] == -1 ? i : u[i-1][j]
        )
      );
    }

    d[m-1][j] = (a[m-1][j] == '0' ? -1 : m-1);
    FORD(i, m-2, 0) {
      d[i][j] = (
        a[i][j] == '0' ? -1 : (
          d[i+1][j] == -1 ? i : d[i+1][j]
        )
      );
    }
  }

  // FOR(i, 0, m-1) {FOR(j, 0, n-1) cerr << l[i][j] << ' '; cerr << '\n';} cerr << '\n';
  // FOR(i, 0, m-1) {FOR(j, 0, n-1) cerr << r[i][j] << ' '; cerr << '\n';} cerr << '\n';
  // FOR(i, 0, m-1) {FOR(j, 0, n-1) cerr << u[i][j] << ' '; cerr << '\n';} cerr << '\n';
  // FOR(i, 0, m-1) {FOR(j, 0, n-1) cerr << d[i][j] << ' '; cerr << '\n';} cerr << '\n';

  int best = -1;
  pair<int, int> pos;
  FOR(i, 0, m-1) {
    FOR(j, 0, n-1) {
      if (a[i][j] == '0') continue;
      int wing = min(
        min(j - l[i][j], r[i][j] - j),
        min(i - u[i][j], d[i][j] - i)
      );
      if (best < wing) {
        best = wing;
        pos = {i, j};
      }
    }
  }
  if (best == -1) cout << "-1\n";
  else {
    cout << best * 4 + 1 << '\n';
    cout << pos.first + 1 << ' ' << pos.second + 1;
  }
}