#include <bits/stdc++.h>
using namespace std;

const int N = 4005, MOD = 1e9 + 7;

int n, a[N], dp[N][N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i];
  }
  dp[1][1] = 1;
  for (int i = 2; i <= n; ++ i) {
    for (int j = 1; j <= i; ++ j) {
      if (a[i] == a[i-1]) {
        dp[i][j] = dp[i-1][i-1];
      } else if (a[i] < a[i-1]) {
        dp[i][j] = dp[i-1][j-1];
      } else {
        dp[i][j] = (dp[i-1][i-1] - dp[i-1][j-1] + MOD) % MOD;
      }
      dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
    }
  }
  cout << dp[n][n];
}