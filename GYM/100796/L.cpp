#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int n, score = 0;
  string s;
  cin >> n >> s;
  // cerr << s << '\n';
  for (int i = 1; i < n; ++ i) {
    string tmp = "";
    tmp += char(s[i-1]);
    tmp += char(s[i]);
    // cerr << tmp << '\n';
    if (tmp == ":)" || tmp == "(:") {
      score ++;
    } else if (tmp == ":(" || tmp == "):") {
      score --;
    }
  }
  if (score > 0) cout << "HAPPY";
  else if (score < 0) cout << "SAD";
  else cout << "BORED";
}