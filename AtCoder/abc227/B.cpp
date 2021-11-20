#include <bits/stdc++.h>
using namespace std;

bool check(int s) {
  for (int a = 1; a <= s; ++ a) {
    int c = 4*a + 3;
    int rest = s - 3 * a;
    if (rest > 0 && (rest % c == 0)) {
      return true;
    }
  }
  return false;
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, x;
  cin >> n;
  int res = n;
  while (n--) {
    cin >> x;
    res -= check(x);
  } 
  cout << res;
}