#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
pair<int, int> a[N];
long long ans[N];

int main() {
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a+1, a+n+1);
  long long rem = k % n;
  long long base = k / n;
  for (int i = 1; i <= rem; ++ i) {
    ans[a[i].second] = base + 1;
  }
  for (int i = rem + 1; i <= n; ++ i) {
    ans[a[i].second] = base;
  }
  for (int i = 1; i <= n; ++ i) {
    cout << ans[i] << '\n';
  }
}