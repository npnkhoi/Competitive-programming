#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 2e5 + 5;

int n, a, b, x[N];

int main() {
  freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int tc; cin >> tc;
  while (tc --) {
    cin >> n >> a >> b;
    FOR(i, 1, n) cin >> x[i];
    int cur = 0;
    long long cost = 0;
    FOR(i, 1, n) {
      while (cur + 1 < i && a < 1LL * b * (n - i + 1)) {
        // cerr << "move next\n";
        cur ++;
        cost += 1LL * a * (x[cur] - x[cur - 1]);
      }
      // cerr << "fire\n";
      cost += 1LL * b * (x[i] - x[cur]);
    }
    cout << cost << '\n';
  }

}