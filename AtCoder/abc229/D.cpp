#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  string s;
  int k;
  cin >> s >> k;
  int l = 0, n = s.size(), cnt = 0, res = 0;
  FOR(r, 0, n-1) {
    cnt += (s[r] == '.');
    while (cnt > k) {
      cnt -= (s[l] == '.');
      l ++;
    }
    res = max(res, r - l + 1);
  }
  cout << res;
}