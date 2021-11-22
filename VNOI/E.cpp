#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 12, X = 1e6 + 2;

int x, n, a[N];
long long dp[N][X];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> x >> n;
  FOR(i, 1, n) cin >> a[i];
  sort(a+1, a+n+1);
  n = unique(a+1, a+n+1) - a - 1;
  // FOR(i, 1, n) cerr << a[i] << ' '; cerr << '\n';
  dp[1][0] = 1;
  FOR(i, 1, n) {
    FOR(s, 0, x) {
      if (i < n) dp[i+1][s] += dp[i][s];
      if (s + a[i] <= x) {
        dp[i][s + a[i]] += dp[i][s];
      }
    }
  }
  cout << dp[n][x];
}