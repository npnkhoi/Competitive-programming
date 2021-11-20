#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k, a[N];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, greater<int>());
  long long s = 0;
  for (int i = k; i <= n; ++ i) {
    s += a[i];
  }
  if (k == 1) cout << s;
  else cout << min(1LL * a[k-1], s);
}