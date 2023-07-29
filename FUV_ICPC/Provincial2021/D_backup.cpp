#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int md = 1e9 + 7;

vector<int> e[3][3];

void knapsack(int l, int r, int lim) {

}

long long f(int l, int r, int val) {

}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, length;
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
    
    e[l][r].push_back(len);
  }

  long long res = 0;

  // prep
  FOR(x, 0, 1) {
    FOR(y, 0, 1) {
      knapsack(x, y, length);
    }
  }

  // 2 2
  for (int l : e[2][2]) {
    if (l == length) res ++;
  }

  // 2 t - (t t) - t 2
  FOR(t, 0, 1) {
    for (int x : e[2][t]) {
      for (int y : e[t][2]) {
        int rem = length - x - y;
        if (rem >= 0) res = (res + f(t, t, rem)) % md;
      }
    }
  }

  // 2 x - (x y - y x) - y 2
  // cnt[x][l]: # pairs (x, 1-x) with total length l
  FOR(x, 0, 1) {
    int y = 1 - x;
    FOR(rem, 0, length) {
      FOR(xy, 0, rem) {
        int yx = rem - xy;
        cnt[x][rem] = (cnt[x][rem] + f(x, y, xy) * f(y, x, yx)) % md;
      }
    }
    for (int l : e[2][x]) {
      for (int r : e[y][2]) {
        int rem = length - l - r;
        if (rem >= 0) {
          res = (res + cnt[x][rem]) % md;
        }
      }
    }
  }

  // 2 x - (x y - y x) - x y - x 2
  FOR(x, 0, 1) {
    int y = 1 - x;
    FOR(rem, 0, length) {
      FOR(xy, 0, rem) {
        int yx = rem - xy;
        cnt[x][rem] = (cnt[x][rem] + f(x, y, xy) * f(y, x, yx)) % md;
      }
    }
    for (int l : e[2][x]) {
      for (int r : e[y][2]) {
        int rem = length - l - r;
        if (rem >= 0) {
          res = (res + cnt[x][rem]) % md;
        }
      }
    }
  }
}