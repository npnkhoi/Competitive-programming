#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7 + 2;

int minFac[MAX];
set<int> s;

void init() {
  memset(minFac, -1, sizeof minFac);
  int lim = 1e7;
  for (int i = 2; i < lim; ++ i) {
    if (minFac[i] == -1) {
      for (long long j = 1LL * i * i; j <= lim; j += i) {
        if (minFac[j] == -1) {
          minFac[j] = i;
        }
      }
    }
  }
}

void count(int x) {
  if (x == 1) {
    return;
  }
  int res = 0;
  while (true) {
    if (minFac[x] == -1) {
      s.insert(x);
      break;
    } else {
      s.insert(minFac[x]);
      x /= minFac[x];
    }
  }
}

int main() {
  int n; cin >> n;
  init();
  for (int i = 0; i < n; ++ i) {
    int a, b; cin >> a >> b;
    s.clear();
    count(a);
    count(b);
    cout << s.size() << '\n';
  }
}