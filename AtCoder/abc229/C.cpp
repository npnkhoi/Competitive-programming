#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 3e5 + 2;
pair<int, int> a[N];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, w;
  cin >> n >> w;
  FOR(i, 0, n-1) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a+n);
  long long res = 0;
  FORD(i, n-1, 0) {
    if (w > 0) {
      int tmp = min(w, a[i].second);
      res += 1LL * tmp * a[i].first;
      w -= tmp;
    }
  }
  cout << res;
}