#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

bool mark[N];

void defactor(int x) {
  for (int i = 2; i <= sqrt(x); ++ i) {
    if (x % i == 0) {
      mark[i] = true;
      while (x % i == 0) x /= i;
      defactor(x);
      return;
    }
  }
  mark[x] = true;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++ i) {
    int x; cin >> x;
    defactor(x);
  }
  vector<int> ans;
  ans.push_back(1);
  
  for (int i = 2; i <= m; ++ i) {
    if (mark[i]) {
      for (int j = i; j <= m; j += i) {
        mark[j] = true;
      }
    } else {
      ans.push_back(i);
    }
  }
  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << '\n';
  }
}