#include <bits/stdc++.h>
using namespace std;

const int md = 1e9 + 7;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int tc; cin >> tc;
  for (int thun = 1; thun <= tc; ++thun) {
    int n; string s;
    cin >> n >> s;
    
    vector<int> cnt(2, 0);
    map<char, int> id;
    id['X'] = 0; id['O'] = 1;
    
    int res = 0, hang = 0;

    for (int i = 0; i < n; ++ i) {
      char c = s[i];

      if (c == 'F') {
        hang ++;
      } else {
        
        res = (res + 1LL * cnt[id[c] ^ 1] * (n - i) % md) % md;
        cnt[id[c]] += cnt[id[c] ^ 1] + 1 + hang;
        cnt[id[c] ^ 1] = 0;
        hang = 0;
      }
    }
    cout << "Case #" << thun << ": " << res << '\n';
  }
}