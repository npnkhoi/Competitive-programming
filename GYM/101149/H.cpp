#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  string s; cin >> s;
  if (s.size() % 2 != 0) {
    cout << "Impossible";
    return 0;
  }

  int cnt = 0, question = 0;
  for (auto c : s) {
    if (c == '(') {
      cnt ++;
    } else if (c == ')') {
      cnt --;
    } else {
      question ++;
    }
  }
  if ((question - cnt) % 2 == 0) {
    int plus = (question - cnt) / 2;
    int minus = (question + cnt) / 2;
    if (plus < 0 || plus > question || minus < 0 || minus > question) {
      cout << "Impossible";
      return 0;
    }
    bool ok = true;
    int tmp = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '?') {
        s[i] = ((plus > 0) ? '(' : ')');
        plus --;
      }
      tmp += ((s[i] == '(') ? 1 : -1);
      if (tmp < 0) ok = false;
    }
    cout << (ok ? s : "Impossible");
  } else {
    cout << "Impossible";
  }
}