#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  string st;
  cin >> st;
  int n = st.size();
  
  vector<int> dp(n+2, 0);
  dp[0] = 1;

  for (int i = 0; i < n; ++ i) {
    for (int j = i-2; j >= 0; --j) {
      dp[i+1] = (dp[i+1] + dp[j]) % MOD;
      if (st[j] == st[i]) break;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++ i) {
    ans = (ans + dp[i+1]) % MOD;
  }
  cout << ans << '\n';
}