#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9 + 2;
const int LEN = 21;

string n;
int k;
unordered_map<int, long long> dp[LEN];

int newProd(int a, int b) {
  long long res = 1LL * a * b;
  res = min(res, INF);
  return res;
}
 
void touch(int a, int b) {
  if (dp[a].find(b) == dp[a].end()) {
    dp[a][b] = 0;
  }
}

int main() {
  cin >> n >> k;
  // dp(i, j): # positive strings that is smaller than the correspoding prefix of N, that has digit-product equal j
  // 20 * something quite small
  
  long long currProd = 1;
  int len = n.size();

  for (int i = 0; i < len; ++i) {
    int currDigit = n[i] - '0';

    // less -> less
    for (auto it = dp[i].begin(); it != dp[i].end(); ++ it) {
      long long prod = it -> first;
      long long val = it -> second;
      for (int d = 0; d < 10; ++ d) {
        touch(i + 1, newProd(prod, d));
        dp[i + 1][newProd(prod, d)] += val;
      }
    }
    // equal -> less
    for (int d = 0; d < currDigit; ++ d) {
      if (i == 0 && d == 0) {
        // do not allow leading zeros
        continue;
      }
      touch(i + 1, newProd(currProd, d));
      dp[i + 1][newProd(currProd, d)] += 1;
    }


    // nowhere -> less
    if (i > 0) {
      for (int d = 1; d < 10; ++d) {
        touch(i + 1, d);
        dp[i + 1][d] += 1;
      }
    }

    // maintain curr
    currProd = min(currProd * currDigit, INF);
  }

  long long res = 0;
  for (auto it = dp[len].begin(); it != dp[len].end(); ++ it) {
    if (it -> first <= k) {
      res += it -> second;
    }
  }
  if (currProd <= k) {
    res ++;
  }

  cout << res;
}