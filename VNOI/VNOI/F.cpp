#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e4 + 2, W = 102;

int tc, n, u, m, w[N], s, cnt[W];
bitset<W*N> bs;

int get_time(int su) {
  int sm = s - su;
  return ceil(max(1.0 * su / u, 1.0 * sm / m));
}

void shift(int d, int c) {
  if (d == 0) return;
  int sh = (d + 1) / 2;
  bs |= (bs << ((1 << sh) * c));
  shift(sh - 1, c);
  bs |= (bs << ((1 << d) * c));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
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
    
    // cerr << s << endl;

    bs.reset();
    bs[0] = true;
    FOR(v, 1, 100) {
      if (cnt[v] == 0) continue;
      shift(cnt[v], v);
      // int d = int(floor(log2(cnt[v])));
      // FORD(i, d, 0) {
      //   if (cnt[v] >> i & 1)
      //     bs = bs | (bs << ((1 << i) * v));
      // }
    }
    
    int res = get_time(0);
    FOR(i, 1, s) {
      if (bs[i]) {
        // cerr << i << '\n';
        res = min(res, get_time(i));
      }
    }
    cout << res << '\n';
  }
}