#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 2e5 + 5;

int n, k;
string s;
int cnt[N];

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int tc;
  cin >> tc;
  while (tc --) {
    cin >> n >> k >> s;
    bool flip = k & 1;
    FOR(i, 0, n-1) {
      cnt[i] = 0; // res]et
      bool bit = (s[i] == '1') ^ flip;
      if (!bit && k > 0) {
        bit ^= 1;
        k --;
        cnt[i] ++;
      }
      s[i] = bit + '0';
    }
    cnt[n-1] += k;
    if (k&1) s[n-1] = ((s[n-1] - '0') ^ 1) + '0';
    cout << s << '\n';
    FOR(i, 0, n-1) cout << cnt[i] << ' '; cout << '\n';
  }
}