#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

vector<pair<int, int>> v;
vector<int> ans;
int a[N], h[N];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i] >> h[i];
    v.push_back({h[i], -i});
    v.push_back({a[i], +i});
  }
  sort(v.begin(), v.end());
  vector<int> best(2, -1);
  int res = 0;
  for (auto x : v) {
    int id = abs(x.second);
    // cerr << "id: " << x.second << '\n';
    if (x.second < 0) { // hit point
      if (best[0] == -1 || a[best[0]] < a[id]) {
        best[1] = best[0];
        best[0] = id;
      } else if (best[1] == -1 || a[best[1]] < a[id]) {
        best[1] = id;
      }
    } else { // attack
      int fr = (best[0] != id ? best[0] : best[1]);
      // cerr << "fr: " << fr << '\n';
      if (fr == -1) continue;
      int sum_attack = a[fr] + (a[fr] >= h[id] ? a[id] : 0);
      if (sum_attack > res) {
        // cerr << "friendly " << id << ' ' << fr << '\n';
        res = sum_attack;
        ans = {id, fr};
      }
    }
  }
  if (ans.empty()) ans = {1, 2};
  cout << res << '\n' << ans[0] << ' ' << ans[1];
}