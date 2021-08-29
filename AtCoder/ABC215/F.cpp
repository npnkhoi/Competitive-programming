#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, INF = 1e9;

int n, minY[2][N], maxY[2][N], x[N];
pair<int, int> a[N];

int maxDiff(int p, int ra) {
  int l = upper_bound(x + 1, x + n + 1, a[p].first - ra) - x;
  int r = upper_bound(x + 1, x + n + 1, a[p].first + ra - 1) - 1 - x;
  // printf("bound of (%d, %d) = %d %d\n", p, ra, l, r);

  int res = 0;
  if (l > 1) {
    res = max(res, maxY[0][l-1] - a[p].second);
    res = max(res, a[p].second - minY[0][l-1]);
  }
  if (r < n) {
    res = max(res, maxY[1][r + 1] - a[p].second);
    res = max(res, a[p].second - minY[1][r + 1]);
  }
  // cerr << res << '\n';
  return res;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i].first >> a[i].second; 
  }
  sort(a + 1, a + n + 1);
  // for (int i = 1; i <= n; ++ i) {
  //   printf("%d %d\n", a[i].first, a[i].second);
  // }
  for (int i = 1; i <= n; ++ i) x[i] = a[i].first;

  minY[0][0] = minY[0][n+1] = minY[1][0] = minY[1][n+1] = INF;
  for (int i = 1; i <= n; ++ i) {
    minY[0][i] = min(minY[0][i - 1], a[i].second);
    maxY[0][i] = max(maxY[0][i - 1], a[i].second);
  }

  for (int i = n; i >= 1; -- i) {
    minY[1][i] = min(minY[1][i + 1], a[i].second);
    maxY[1][i] = max(maxY[1][i + 1], a[i].second);
  }

  int res = 0;
  for (int i = 1; i <= n; ++ i) {
    int l = 0, r = INF, bs = l;
    while (l <= r) {
      // printf("l = %d, r = %d\n", l, r);
      int mid = (l + r) / 2;
      if (maxDiff(i, mid) >= mid) {
        bs = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    res = max(res, min(bs, maxDiff(i, bs)));
    // printf("bs = %d, maxDiff = %d\n", bs, maxDiff(i, bs));
    
    l = 0, r = INF, bs = r;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (maxDiff(i, mid) <= mid) {
        bs = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    res = max(res, min(bs, maxDiff(i, bs)));
    // printf("bs = %d, maxDiff = %d\n", bs, maxDiff(i, bs));
  }
  cout << res;
}