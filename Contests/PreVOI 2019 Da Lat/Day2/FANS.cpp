#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <bitset>
#include <complex>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < n; ++i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,b,a) for (int i = b; i >= a; --i)

#define all(v) v.begin(), v.end()
#define debug(a) cerr << #a << " = " << a << "\n"

#define task "FANS"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = 2e4 + 2;

ll f[N][3][5][5], s[N][3][5];
int n, md, id;
string str;

void inc(ll &a, ll b) {
  a += b;
  if (md != 0) a %= md;
}

void dp() {
  memset(f, 0, sizeof f);
  memset(s, 0, sizeof s);
  f[0][2][2][2] = 1;

  FOR(len, 0, n - 1) {
    FOR(mi, 0, 2) {
      FOR(mx, 2, mi + 2) {
        FOR(cur, mi, mx) {
          if (cur - 1 >= 0 && mx - cur + 1 <= 2) {
            inc(f[len + 1][min(mi, cur - 1)][mx][cur - 1], f[len][mi][mx][cur]);
          }
          if (cur + 1 <= 4 && cur + 1 - mi <= 2) {
            inc(f[len + 1][mi][max(mx, cur + 1)][cur + 1], f[len][mi][mx][cur]);
          }
        }
      }
    }
  }
}

void calc() {
  int cur = 2, mi = 2, mx = 2;
  ll res = 1;
  FOR(i, 1, n) {
    if (str[i - 1] == 'V') {
      if (cur == 0) continue;
      int mi2 = mx - 2, mx2 = 2 + min(mi, cur - 1);
      FOR(x, mi2, 2) FOR(y, 2, min(mi2 + 2, mx2)) FOR(cur, x, y)
        inc(res, f[n - i][x][y][cur]);
    }
    cur += (str[i - 1] == 'M' ? -1 : +1);
    mi = min(mi, cur);
    mx = max(mx, cur);
  }
  cout << res << '\n';
}

bool getBit(int x, int i) {
  return (x >> i) & 1;
}

void sub1() {
  id = 0;
  REP(i, n) if (str[n - 1 - i] == 'V') id += (1 << i);
  int cnt = 0;
  REP(mask, id + 1) {
    int cur = 0, mi = 0, ma = 0;
    bool flag = 1;
    REP(i, n) {
      if (getBit(mask, i)) cur ++; else cur --;
      if (cur - mi > 2 || ma - cur > 2) {
        flag = 0;
        break;
      }
      mi = min(mi, cur);
      ma = max(ma, cur);
    }
    cnt += flag;
  }
  if (md == 0) cout << cnt << '\n';
  else cout << cnt % md << '\n';
}

int main() {
  ios::sync_with_stdio();
  cin.tie(0); cout.tie(0);
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);
  int tc; cin >> tc;
  while (tc --) {
    cin >> n >> md >> str;
    dp(); calc();
    /*if (n <= 20) sub1();
    else {
      dp();
      calc();
    }*/
  }
}
