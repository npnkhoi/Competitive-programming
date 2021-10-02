#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, a[N], b[N], c[N], mark[N], fw[N];

void update(int pos, int delta) {
  for (; pos <= n; pos += pos&(-pos)) {
    fw[pos] += delta;
  }
}

int get(int pos) {
  if (pos == 0) return 0;
  int ret = 0;
  for (; pos; pos -= pos&(-pos)) {
    ret += fw[pos];
  }
  return ret;
}

void solve(int a[], int b[]) { 
  vector<pair<pair<int, int>, int>> v;
  for (int i = 1; i <= n; ++ i) {
    v.push_back({{a[i], b[i]}, i});
  }
  sort(v.begin(), v.end());
  
  memset(fw, 0, sizeof fw);
  for (auto x : v) {
    if (get(x.first.second - 1) > 0) {
      mark[x.second] = 1;
    }
    update(x.first.second, +1);
  }
}

void compress(int a[]) {
  vector<int> v;
  for (int i = 1; i <= n; ++ i) {
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; ++ i) {
    a[i] = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
  }
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  compress(a);
  compress(b);
  compress(c);

  solve(a, b);
  solve(b, c);
  solve(c, a);
  
  vector<int> ans;
  for (int i = 1; i <= n; ++ i) if (!mark[i]) ans.push_back(i);
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
}