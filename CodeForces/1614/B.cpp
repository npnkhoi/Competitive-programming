#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N= 2e5 + 2;

pair<int, int> a[N];
int coor[N];

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    FOR(i, 0, n-1) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a,a+n);
    int counter = 1;
    long long res = 0;
    FORD(i, n-1, 0) {
      counter ++;
      if (counter % 2) {
        coor[a[i].second] = counter / 2;
      } else {
        coor[a[i].second] = - counter / 2;
      }
      res += 1LL * counter / 2 * 2 * a[i].first;
    }
    cout << res << '\n';
    cout << "0 ";
    FOR(i, 0, n-1) {
      cout << coor[i] << ' ';
    }
    cout << '\n';
  }
}