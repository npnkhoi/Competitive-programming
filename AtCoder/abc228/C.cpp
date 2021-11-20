#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];
int n, k;

int highest(int val) {
  int pos = upper_bound(a+1, a+n+1, val) - a;
  return n - pos + 2;
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; ++ i) {
    int x, y, z;
    cin >> x >> y >> z;
    a[i] = x + y + z;
    b[i] = a[i];
  }
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; ++ i) {
    if (highest(b[i] + 300) <= k) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}