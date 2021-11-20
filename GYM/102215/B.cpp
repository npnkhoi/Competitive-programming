#include <bits/stdc++.h>
using namespace std;

int cnt[4], n;
const int type_ord[] = {1, 3, 2, 0};

void result() {
  for (int row = 0; row < 2; ++ row) {
    for (int type : type_ord) {
      for (int i = 0; i < cnt[type]; ++ i) {
        cout << ((type >> (1 - row) & 1) ? '#' : '.');
      }
    }
    cout << '\n';
  }
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  string a, b;
  cin >> a >> b;
  n = a.size();
  for (int i = 0; i < n; ++ i) {
    int tmp = int(a[i] == '#') * 2 + int(b[i] == '#');
    cnt[tmp] ++;
  }
  if (cnt[2] && cnt[1] && (cnt[3] == 0)) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    result();
  }
}