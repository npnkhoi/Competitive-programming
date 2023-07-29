#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  char best = 'z';
  FOR(i, 0, n-1) {
    best = min(best, s[i]);
  }

  vector<int> v;
  string res = "";
  FOR(t, 1, k) {
    res += best;
    FOR(i, 0, n-1) {
      if (s[i] == best) {
        v.push_back(i);
      }
    }
    best = 'z';
    for (int x: v) {
      if (x > 0) best = min(best, s[x-1]);
      if (x < n-1) best = min(best, s[x+1]);
    }
    v.clear();
  }
  cout << res;
}