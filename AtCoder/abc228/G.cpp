#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int MASK = (1 << 10) + 2, D = 12, md = 998244353, N = 302;

int row2col[MASK][D], col2row[MASK][D], dp[2*N][MASK];
string a[D];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int h, w, n;
  cin >> h >> w >> n;
  FOR(i, 0, h-1) {
    cin >> a[i];
  }

  // prepare
  FOR(setRow, 0, (1 << h) - 1) {
    FOR(row, 0, h-1) {
      if ((setRow >> row & 1) == 0) continue;
      FOR(col, 0, w-1) {
        row2col[setRow][a[row][col] - '0'] |= (1 << col);
      }
    }
  }
  FOR(setCol, 0, (1 << w) - 1) {
    FOR(col, 0, w-1) {
      if ((setCol >> col & 1) == 0) continue;
      FOR(row, 0, h-1) {
        col2row[setCol][a[row][col] - '0'] |= (1 << row);
      }
    }
  }

  // DP
  dp[0][(1 << h) - 1] = 1;
  FOR(i, 0, 2 * n - 1) {
    if (i % 2 == 0) {
      FOR(s, 1, (1 << h) - 1) {
        FOR(c, 1, 9) {
          int t = row2col[s][c];
          dp[i+1][t] = (dp[i+1][t] + dp[i][s]) % md;
        }
      }
    } else {
      FOR(s, 1, (1 << w) - 1) {
        FOR(c, 1, 9) {
          int t = col2row[s][c];
          dp[i+1][t] = (dp[i+1][t] + dp[i][s]) % md;
        }
      }
    }
  }

  // FOR(i, 0, 2*n) {
  //   FOR(j, 0, ((1 << max(h, w)) - 1)) {
  //     cerr << dp[i][j] << ' ';
  //   }
  //   cerr << '\n';
  // }

  // Result
  int res = 0;
  FOR(s, 1, (1 << h) - 1) {
    res = (res + dp[2 * n][s]) % md;
  }
  cout << res;
}