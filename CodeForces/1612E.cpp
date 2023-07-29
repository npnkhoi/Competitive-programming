#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int M = 2e5 + 1, N = 2e5 + 3;

vector<int> reader[N], pinList;
pair<long long, int> cnt[N];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, m, k;
  cin >> n;
  FOR(i, 1, n) {
    cin >> m >> k;
    reader[m].push_back(k);
  }
  double best = 0;
  int cntPin;

  // t <= 20
  FOR(t, 1, 20) {
    FOR(i, 1, M) {
      cnt[i] = {0, i};
      for (int x : reader[i]) {
        cnt[i].first += min(t, x);
      }
    }
    sort(cnt + 1, cnt + M + 1);
    long long tmp = 0;
    FORD(i, M, (M-t+1)) {
      tmp = tmp + cnt[i].first;
    }
    if (1.0 * tmp / t > best) {
      best = 1.0 * tmp / t;
      cntPin = t;
      pinList.clear();
      FOR(i, M-t+1, M) {
        pinList.push_back(cnt[i].second);
      }
    }
  }

  // t > 20
  int flag = -1;
  FOR(i, 1, M) {
    cnt[i] = {0, i};
    for(int x: reader[i]) cnt[i].first += x;
  }
  sort(cnt + 1, cnt + M + 1);
  long long tmp = 0;
  FORD(i, M, 1) {
    tmp += cnt[i].first;

    if (M - i + 1 >= 20 && 1.0 * tmp / (M - i + 1) > best) {
      best = 1.0 * tmp / (M - i + 1);
      flag = i;
      cntPin = (M - i + 1);
    }
  }
  
  // Result
  cout << cntPin << '\n';
  if (flag == -1) {
    for (int x: pinList) cout << x << ' '; cout << '\n';
  } else {
    FOR(i, flag, M) cout << cnt[i].second << ' '; cout << '\n';
  }
}