#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e6 + 5;

int n, a[N], b[N], fw[N];
long long l[N], r[N];

void update(int i, int del) {
  for (; i <= n; i += i&(-i)) {
    fw[i] += del;
  }
}

int get(int i) {
  int ret = 0;
  for (; i; i -= i & (-i)) {
    ret += fw[i];
  }
  return ret;
}

int get(int l, int r) {
  if (l > r) return 0;
  if (l == 1) return get(r);
  return get(r) - get(l - 1);
}

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i];
    b[a[i]] = i;
  }
  FOR(i, 1, n) {
    l[i] = l[i - 1] + get(b[i] + 1, n);
    update(b[i], 1);
  }
  memset(fw, 0, sizeof fw);
  FORD(i, n, 1) {
    r[i] = r[i+1] + get(1, b[i] - 1);
    update(b[i], 1);
  }
  // FOR(i, 1, n) cerr << l[i] << ' '; cerr << '\n';
  // FOR(i, 1, n) cerr << r[i] << ' '; cerr << '\n';
  long long res = 1e18;
  FOR(i, 1, n) {
    res = min(res, l[i - 1] + r[i + 1]);
  }
  cout << res;
}