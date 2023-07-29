#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

map<long long, int> cnt;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n;
  long long k;
  cin >> n >> k;
  cnt[0] = 1; 
  long long res = 0, total = 0;
  FOR(i, 1, n) {
    int val;
    cin >> val;
    total += val;
    res += cnt[total - k];
    cnt[total] = cnt[total] + 1;
  }
  cout << res;
}