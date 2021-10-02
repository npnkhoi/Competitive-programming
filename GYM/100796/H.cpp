#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  long long m, n;
  cin >> n >> m;
  cout << m * n + min(m, n);
}