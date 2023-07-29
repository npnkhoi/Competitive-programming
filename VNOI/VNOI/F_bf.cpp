#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e4 + 2, W = 102;

int tc, n, u, m, w[N], s, cnt[W];
bitset<W*N> bs;

int get_time(int su) {
  int sm = s - su;
  return max((su + u - 1) / u, (sm + m - 1) / m);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen("test.inp", "r", stdin);
  freopen("test.ans", "w", stdout);
  cin >> tc;
  while (tc--) {
    cin >> n >> u >> m;
    s = 0;
    memset(cnt, 0, sizeof cnt);
    FOR(i, 1, n) {
      cin >> w[i];
      s += w[i];
      cnt[w[i]] ++;
    }
    
    int res = s;
    FOR(mask, 0, (1 << n) - 1) {
      int tmp = 0;
      FOR(i, 0, n-1) {
        if (mask >> i & 1) {
          tmp += w[i+1];
        }
      }
      res = min(res, get_time(tmp));
    }
    cout << res << '\n';
  }
}