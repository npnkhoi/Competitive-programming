#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

pair<pair<int, int>, int> a[N];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int tc, n;
  cin >> tc;
  while (tc --) {
    cin >> n;
    long long num_votes = 0, sum_pleasure = 0;
    for (int i = 1; i <= n; ++ i) {
      cin >> a[i].first.first >> a[i].first.second;
      a[i].second = i;
      sum_pleasure += a[i].first.first * a[i].first.second;
      num_votes += a[i].first.second;
    }
    sort(a+1, a+n+1);
    vector<int> ans;
    for (int i = n; i >= 1; --i) {
      int p = a[i].first.first;
      if (sum_pleasure < num_votes * p) {
        sum_pleasure += p;
        num_votes += 1;
        ans.push_back(a[i].second);
      }
    }
    sort(ans.begin(), ans.end());
    long long tmp = __gcd(sum_pleasure, num_votes);
    sum_pleasure /= tmp;
    num_votes /= tmp;
    cout << sum_pleasure << '/' << num_votes << '\n';
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' '; cout << '\n';
  }
}