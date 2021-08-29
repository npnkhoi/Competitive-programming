#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 4;

int minFac[MAX + 2];

void init() {
  memset(minFac, -1, sizeof minFac);
  for (int i = 2; i <= MAX; ++ i) {
    if (minFac[i] == -1) {
      for (long long j = 1LL * i * i; j <= MAX; j += i) {
        if (minFac[j] == -1) {
          minFac[j] = i;
        }
      }
    }
  }
}

int main() {
  freopen("D.inp", "r", stdin);
  freopen("D.out", "w", stdout);
  init();
  int tc; cin >> tc;
  while (tc --) {
    int n; cin >> n;
    vector<int> v;
    n += 2;
    for (int i = 1; i <= sqrt(n); ++ i) {
      if (n % i == 0) {
        if (i > 2 && minFac[i] == -1) {
          v.push_back(i);
        }
        if (i * i != n && minFac[n/i] == -1) {
          v.push_back(n / i);
        }
      }
    }
    if (v.empty()) {
      cout << "-1\n";
    } else {
      sort(v.begin(), v.end());
      for (int i = 0; i < v.size(); ++ i) {
        cout << v[i];
        if (i < v.size() - 1) {
          cout << ' ';
        }
      }
      cout << '\n';
    }
  }
}