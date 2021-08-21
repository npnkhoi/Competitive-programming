#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, INF = 2e9;
typedef pair<int, int> Pack;

int n, s[N], t[N], ans[N];
priority_queue<Pack, vector<Pack>, greater<Pack>> heap;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++ i) {
    cin >> s[i];
  }

  for (int i = 0; i < n; ++ i) {
    cin >> t[i];
    pair<int, int> tmp = {t[i], i};
    heap.push(tmp);
    ans[i] = INF;
  }

  while (!heap.empty()) {
    Pack u = heap.top(); heap.pop();
    if (u.first < ans[u.second]) {
      ans[u.second] = u.first;
      heap.push({u.first + s[u.second], (u.second + 1) % n});
    }
  }
  for (int i = 0; i < n; ++ i) {
    cout << ans[i] << '\n';
  }
}