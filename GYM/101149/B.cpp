#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

pair<int, int> a[N];
int n;
long long s;

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first - a.second > b.first - b.second;
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i].first >> a[i].second;
    s += a[i].second;
  }
  sort(a + 1, a + n + 1, cmp);
  long long tmp = s;
  for (int i = 1; i <= n; ++ i) {
    if (tmp < a[i].first) {
      s += a[i].first - tmp;
      tmp = a[i].first;
    }
    tmp -= a[i].second;
  }
  cout << s;
}