#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e5 + 2, A = 2e7;

int a[N], cnt[A], cntMul[A], fac[A];
long long dp[A];

void sieve() {
  FOR(i, 2, A) {
    if (fac[i] == 0) {
      for (long long j = 1LL * i * i; j <= A; j += i) {
        if (fac[j] == 0) fac[j] = i;
      }
    }
  }
}

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  sieve();  
  int n;
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i];
    cnt[a[i]] ++;
    FOR(x, 1, sqrt(a[i])) {
      if (a[i] % x == 0) {
        cntMul[x] ++;
        if (x * x < a[i]) {
          cntMul[a[i] / x] ++;
        }
      }
    }
  }
  FORD(t, A, 1) {
    if (dp[t] == 0 && cnt[t] > 0) {
      dp[t] = 1LL * t * cnt[t];
    }
    if (dp[t] == 0) continue;
    int x = t;
    while (x != 1) {
      int f = (fac[x] == 0 ? x : fac[x]);
      dp[t / f] = max(dp[t / f], dp[t] + 1LL * (t / f) * (cntMul[t / f] - cntMul[t]));
      while (x % f == 0) x /= f;
    }
  }
  // FOR(i, 1, 6) {
  //   cerr << dp[i] << ' ' << cntMul[i] << '\n';
  // }
  cout << dp[1];
}