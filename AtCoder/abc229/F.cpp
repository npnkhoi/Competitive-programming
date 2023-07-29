#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 2e5 + 2;

long long ans = 1e18, dp[N];
int n, a[N], b[N];

void solve() {
  dp[1] = b[1];
  FOR(i, 2, n) {
    dp[i] = min(dp[i-1] + b[i], dp[i-2] + a[i]);
  }
  ans = min(ans, dp[n]);
  // FOR(i, 1, n) {
  //   cerr << dp[i] << ' ';
  // }
  // cerr << '\n';
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  solve();
  pair<int, int> tmp = {a[1], b[1]};
  FOR(i, 1, n-1) {
    a[i] = a[i+1];
    b[i] = b[i+1];
  }
  a[n] = tmp.first;
  b[n] = tmp.second;
  solve();
  cout << ans << '\n';
}