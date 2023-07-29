#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1005;

int n;
pair<int, int> a[N];

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  
  long long minDist = 1e18;
  int ans;
  FOR(i, 1, n) {
    long long dist = 0;
    FOR(j, 1, n) {
      dist += abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
    }
    // cerr << a[i].first << ' ' << a[i].second << ' ' << dist << '\n';
    if (dist < minDist) {
      minDist = dist;
      ans = i;
    }
  }
  cout << a[ans].first << ' ' << a[ans].second;
}