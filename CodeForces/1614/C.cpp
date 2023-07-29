#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int L = 31, N = 2e5 + 2, md = 1e9+7;

int cnt[L][N];
pair<pair<int, int>, int> a[N];

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int tc, n, m;
  cin >> tc;
  while (tc --) {
    cin >> n >> m;
    FOR(i, 1, m) {
      int l, r, x;
      cin >> l >> r >> x;
      a[i] = {{l, r}, x};
      FOR(i, 0, L-1) {
        if ((x >> i & 1) == 0) {
          cnt[i][l] += 1;
          cnt[i][r + 1] -= 1;
        }
      }
    }
    int k = 1;
    FOR(i, 1, n-1) {
      k = k * 2 % md;
    }
    int res = 0;
    FOR(i, 0, L-1) {
      int tmp = 0;
      bool ok = false;
      FOR(j, 1, n) {
        tmp += cnt[i][j];
        if (tmp == 0) { // found a One
          ok = true;
        }
      }
      if (ok) {
        res = (res + (1LL << i) * k % md) % md;
      }
    }
    cout << res << '\n';
    FOR(p, 1, m) {
      FOR(i, 0, L-1) {
        if ((a[p].second >> i & 1) == 0) {
          cnt[i][a[p].first.first] -= 1;
          cnt[i][a[p].first.second + 1] += 1;
        }
      }
    }
  }
}