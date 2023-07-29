#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e4 + 2, INF = 1e9;

int dp[2][2][2*N], a[N][2];

void setMin(int &x, int y) {
  x = min(x, y);
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n;
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i][0] >> a[i][1];
  }
  FOR(p, 0, 1) {
    FOR(k, 1, 2*n) {
      dp[1][p][k] = 1;
    }
  }
  int best = 1;

  FOR(i, 2, n) {
    int cur = i % 2, pre = cur ^ 1, tmp = INF;
    FOR(p, 0, 1) {
      int k1 = a[i][p];
      FOR(k2, 1, 2*n) {
        dp[cur][p][k2] = best + 1;
        if (a[i-1][0] == k1) {
          setMin(dp[cur][p][k2], dp[pre][0][k2]); 
        }
        if (a[i-1][1] == k1) {
          setMin(dp[cur][p][k2], dp[pre][1][k2]); 
        }
        if (a[i-1][0] == k2) {
          setMin(dp[cur][p][k2], dp[pre][0][k1]);
        }
        if (a[i-1][1] == k2) {
          setMin(dp[cur][p][k2], dp[pre][1][k1]);
        }
        
        setMin(tmp, dp[cur][p][k2]);
      }
    }
    best = tmp;
  }
  cout << best;
}