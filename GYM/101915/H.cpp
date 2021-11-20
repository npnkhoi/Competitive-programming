#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

vector<pair<int, int>> v;
int cnt[N];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int tc, n, k;
  cin >> tc;
  while (tc --) {
    memset(cnt, 0, sizeof cnt);
    v.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) {
      for (int j = 0; j < 3; ++ j) {
        int x;
        cin >> x;
        v.push_back({x, i});
      }
    }
    sort(v.begin(), v.end());
    int bought = 0;
    long long cost = 0;
    for (int i = 0; i < v.size() && bought < k; ++ i) {
      if (cnt[v[i].second] < 2) {
        cnt[v[i].second] ++;
        bought ++;
        cost += v[i].first;
      }
    }
    cout << cost << '\n';
  }
}