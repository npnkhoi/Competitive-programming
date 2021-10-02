#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int tc; cin >> tc;
  for (int thun = 1; thun <= tc; ++thun) {
    int n; string s;
    cin >> n >> s;
    char cur = 'A';
    int cnt = 0;
    for (auto c : s) {
      if (c == 'F') continue;
      if (c != cur) {
        cnt ++;
        cur = c;
      }
    }
    if (cnt == 0) cnt = 1; // full F 
    cout << "Case #" << thun << ": " << cnt-1 << '\n';
  }
}