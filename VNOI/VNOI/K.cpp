#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int LIM = 1e9, N = 1e6 + 2;

pair<int, int> a[N];
int lf[N], rt[N];
int n;

long long totalDist(int x, int y) {
  long long ret = 0;
  FOR(i, 1, n) {
    ret += max(abs(a[i].first - x), abs(a[i].second - y));
  }
  return ret;
}

long long totalDist(int y) {
  FOR(i, 1, n) {
    int d = abs(y - a[i].second);
    lf[i] = a[i].first - d;
    rt[i] = a[i].first + d;
  }
  // sort(lf + 1, lf + n + 1);
  // sort(rt + 1, rt + n + 1);

  int l = -LIM, r = LIM, ans = r;
  while (l <= r) {
    int mid = (l + r) / 2;
    int cntLeft = lower_bound(lf + 1, lf + n + 1, mid) - lf - 1;
    int cntRight = n - (upper_bound(rt + 1, rt + n + 1, mid) - lf) + 1;
    if (cntLeft >= cntRight) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return totalDist(ans, y);
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  
  cin >> n;
  FOR(i, 1, n) cin >> a[i].first >> a[i].second;
  int l = -LIM, r = LIM, ans = r;
  while (l <= r) {
    cerr << "considering " << l << ' ' << r << '\n';
    int mid = (l + r) / 2;
    if (totalDist(mid) <= totalDist(mid + 1)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << totalDist(ans);
}