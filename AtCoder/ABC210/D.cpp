#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int a[N][N];
long long f[N][N];
long long res = 8e18;
int h, w, c;

void solve() {
  f[0][0] = a[0][0];
  for (int i = 1; i < h; ++ i) {
    f[i][0] = min(f[i-1][0] + c, 1LL * a[i][0]);
    res = min(res, f[i-1][0] + c + a[i][0]);
  }
  for (int i = 1; i < w; ++ i) {
    f[0][i] = min(f[0][i-1] + c, 1LL * a[0][i]);
    res = min(res, f[0][i-1] + c + a[0][i]);
  }
  for (int i = 1; i < h; ++ i) {
    for (int j = 1; j < w; ++ j) {
      long long tmp = min(f[i-1][j], f[i][j-1]) + c;
      res = min(res, tmp + a[i][j]);
      f[i][j] = min(tmp, (long long) a[i][j]);
      // printf("f(%d, %d) = %lld\n", i, j, f[i][j]);
    }
  }
}

int main() {
  scanf("%d%d%d", &h, &w, &c);
  for (int i = 0; i < h; ++ i) {
    for (int j = 0; j < w; ++ j) {
      scanf("%d", &a[i][j]);
    }
  }
  solve();
  for (int i = 0; i < h/2; ++i) {
    for (int j = 0; j < w; ++ j) {
      swap(a[i][j], a[h-1-i][j]);
    }
  }
  solve();
  printf("%lld\n", res);
}