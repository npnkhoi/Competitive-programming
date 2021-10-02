#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e9, N = 1e5 + 5;

int n, k, a[N];
long long sat;

long long count(long long x) {
  long long ret = 0;
  sat = 0;
  for (int i = 0; i < n; ++ i) {
    if (a[i] >= x) {
      ret += a[i] - x + 1;
      sat += (1LL * a[i] * (a[i] + 1) - 1LL * x * (x - 1)) / 2;
    }
  }
  return ret;
}

int main() {
  freopen("E.inp", "r", stdin);
  freopen("E.out", "w", stdout);
  
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++ i) cin >> a[i];
  long long l = 0, r = MAX + 1, bs = l;
  // cerr << "hello\n";
  while (l <= r) {
    // cerr << l << ' ' << r << '\n'; 
    long long mid = (l + r) / 2;
    if (count(mid) >= k) {
      bs = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  long long cnt = count(bs);
  if (k > cnt) k = cnt;
  cout << sat - 1LL * bs * (cnt - k);
}