#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], mark[N];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i];
  }
  mark[x] = 1;
  int cnt = 1;
  while (true) {
    if (!mark[a[x]]) {
      x = a[x];
      mark[x] = 1;
      cnt ++;
    } else {
      break;
    }
  }
  cout << cnt;
}