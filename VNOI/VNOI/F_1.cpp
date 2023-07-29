#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e4 + 2;

int tc, n, u, m, a[N];

int rearest(int val) {
  
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> tc;
  while (tc--) {
    cin >> n >> u >> m;
    long long s = 0;
    FOR(i, 1, n) {
      cin >> a[i];
      s += a[i];
    }
    int best = nearest(s * u / (u + m));
    long long res = max((best + u - 1) / u, (s - best + m - 1) / m);
    best = nearest(s * m / (u + m));
    res = min(res, max((best + m - 1) / m, (s - best + u - 1) / u));
    cout << res << '\n';
  }
}