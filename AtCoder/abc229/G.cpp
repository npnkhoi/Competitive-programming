#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const long long INF = 1e18;

string s;
int n;
long long k;
vector<int> v;
vector<long long> t;

long long getSum(int l, int r) {
  if (l > r) return 0;
  if (l == 0) return t[r];
  else return t[r] - t[l - 1];
}

long long cost(int d) {
  int l = 0;
  long long ret = INF;
  int sizeV = v.size();
  FOR(r, d-1, sizeV - 1) {
    int l = r - d + 1;
    int mid = (l + r) / 2;
    long long leftSum = 1LL * v[mid] * (mid - l) - getSum(l, mid - 1);
    long long rightSum = getSum(mid + 1, r) - 1LL * v[mid] * (r - mid);
    ret = min(ret, leftSum + rightSum);
  }
  return ret;
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> s >> k;
  n = s.size();
  long long curSum = 0;
  FOR(i, 0, n-1) {
    if (s[i] == 'Y') {
      int tmp = i - v.size();
      v.push_back(tmp);
      curSum += tmp;
      t.push_back(curSum);
    }
  }
  if (v.size() == 0) {
    cout << 0;
    return 0;
  }
  // for (int x : v) cerr << x << ' '; cerr << '\n';
  // for (int x : t) cerr << x << ' '; cerr << '\n';
  int l = 1, r = v.size(), ans = l;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (cost(mid) <= k) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans;
  // cerr << ans << ' ' << cost(ans) << '\n';
}