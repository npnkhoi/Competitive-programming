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

int n, md, id;
string str;

bool getBit(int x, int i) {
  return (x >> i) & 1;
}

void sub1() {
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
    id = 0;
    REP(i, n) if (str[n - 1 - i] == 'V') id += (1 << i);
    //cerr << id << '\n';
    sub1();
  }

}
