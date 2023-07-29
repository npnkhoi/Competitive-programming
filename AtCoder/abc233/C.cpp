#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1e5 + 2;

vector<int> a[N];
map<long long, long long> cnt, backup;

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int n;
  long long x;
  cin >> n >> x;
  FOR(i, 1, n) {
    int l, tmp;
    cin >> l;
    while (l--) {
      cin >> tmp;
      a[i].push_back(tmp);
    }
  }
  cnt[x] = 1;
  FORD(i, n, 1) {
    backup = cnt;
    cnt.clear();
    for (int val : a[i]) {
      for (auto it = backup.begin(); it != backup.end(); it ++) {
        if ((it -> first) % val == 0) {
          cnt[(it -> first) / val] += (it -> second);
        }
      }
    }
  }
  cout << cnt[1];
}