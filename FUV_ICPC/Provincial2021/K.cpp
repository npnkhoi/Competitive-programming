#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int n, y, z;
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  cin >> y >> z;
  
  y = abs(y - z);
  FOR(i, 1, n) a[i] = abs(a[i] - z);
  sort(a + 1, a + n + 1);

  long long tmp = 0;
  int res = 0;
  
  FOR(i, 1, n) {
    tmp += a[i];
    if (tmp < y) res = i;
    else break;
  }
  cout << res;
}