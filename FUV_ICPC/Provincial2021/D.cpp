#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int md = 1e9 + 7, N = 305;

vector<int> e[3][3];
int n, length, dp[3][3][N][N][N], cntNone[2][N], cnt[2][N], cntSame[2][N], cntNoneXNone[2][N], freq[2][N];

void knapsack(int l, int r, int lim) {
  // dp[l][r][i][num][lim]

  dp[l][r][0][0][0] = 1;
  FOR(i, 1, e[l][r].size()) {
    FOR(num, 0, lim) {
      FOR(len, 0, lim) {
        dp[l][r][i][num][len] = dp[l][r][i-1][num][len];
        if (e[l][r][i-1] <= len) {
          dp[l][r][i][num][len] = (dp[l][r][i][num][len] + dp[l][r][i-1][num - 1][len - e[l][r][i-1]]) % md;
        }
      }
    }
  }
}

long long f(int l, int r, int num, int val) {
  return dp[l][r][e[l][r].size()][num][val];
}

long long countDp(int l, int r, int val) {
  int ret = 0;
  FOR(d, 0, length) {
    ret = (ret + f(l, r, d, val)) % md;
  }
  return ret;
}

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  cin >> n >> length;
  FOR(i, 1 , n) {
    int len;
    string sl, sr;
    int l, r;
    cin >> len >> sl >> sr;
    if (sl == "none") l = 2;
    else l = (sl == "in" ? 1 : 0);
    
    if (sr == "none") r = 2;
    else r = (sr == "in" ? 0 : 1);
    // cerr << len << ' ' << l << ' ' << r << '\n';
    e[l][r].push_back(len);
    if (l == 2 && r != 2) {
      freq[r][len] ++;
    } else if (r == 2 && l != 2) {
      freq[l][len] ++;
    }
  }

  long long res = 0;

  // prep
  FOR(x, 0, 1) {
    FOR(y, 0, 1) {
      knapsack(x, y, length);
    }
  }

  // CASE 2 2 -------------------------------
  for (int l : e[2][2]) {
    if (l == length) res ++;
  }
  // cerr << res << '\n';

  // CASE 2 t - (t t) - t 2 --------------------
  FOR(t, 0, 1) {
    for (int x : e[2][t]) {
      for (int y : e[t][2]) {
        int rem = length - x - y;
        if (rem >= 0) res = (res + countDp(t, t, rem)) % md;
      }
    }
  }
  // cerr << res << '\n';

  // PREPARE CNTNONE AND CNT -------------------
  FOR(side, 0, 1) {
    FOR(len, 1, length) {
      FOR(mid, 1, len) {
        cntNone[side][len] = (cntNone[side][len] + freq[side][mid] * countDp(side, side, len - mid) % md) % md;
      }
    }
  }
  
  // cnt[x][l]: # pairs 2 x (x x), (1-x 1-x) 1-x 2 with total length l
  FOR(x, 0, 1) {
    int y = 1 - x;
    FOR(l, 1, length) {
      FOR(r, 1, length - l) {
        cnt[x][l + r] = (cnt[x][l + r] + 1LL * cntNone[x][l] * cntNone[y][r] % md) % md;
      }
    }
  }

  // CASE 2 x - (x y - y x) - x 2 ----------------------------------
  // 2 x - (x x) - x 2, len

  FOR(x, 0, 1) {
    for (int l : e[2][x]) {
      for (int r : e[x][2]) {
        if (l + r <= length) cntNoneXNone[x][l + r] ++;
      }
    }
    FOR(mid, 0, length) {
      FOR(twoSide, 0, length - mid) {
        int total = mid + twoSide;
        cntSame[x][total] = (cntSame[x][total] + 1LL * cntNoneXNone[x][twoSide] * countDp(x, x, mid) % md) % md;
      }
    }
  }
  FOR(x, 0, 1) {
    int y = 1 - x;
    FOR(d, 1, length) {
      FOR(xy, 0, length) {
        FOR(yx, 0, length - xy) {
          res = (res + f(x, y, d, xy) * f(y, x, d, yx) % md * cntSame[x][length - xy - yx] % md) % md;
        }
      }
    }
  }
  // cerr << res << '\n';

  // CASE 2 x - (x y - y x) - x y - y 2 -------------------------------
  FOR(x, 0, 1) {
    int y = 1 - x;
    FOR(d, 0, length - 1) {
      FOR(xy, 0, length) {
        FOR(yx, 0, length - xy) {
          res = (res + f(x, y, d + 1, xy) * f(y, x, d, yx) % md * cnt[x][length - xy - yx] % md) % md; // BUG
        }
      }
    }
    // cerr << "- " << res << '\n';
  }
  // cerr << res << '\n';

  cout << res;
}