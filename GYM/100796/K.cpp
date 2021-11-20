#include <bits/stdc++.h>
using namespace std;

const long long LIM = 1e18 + 1e17;

long long fac[30];
map<long long, bool> memo;
set<long long> hub;

bool profact(long long x) {
  // if (x == 1) return true;
  // if (memo.find(x) != memo.end()) return memo[x];

  // bool res = false;
  // while (x % fac[max_fac] != 0) max_fac --;
  // if (max_fac == 1) {
    
  // } else {
  //   for (int i = max_fac; i >= 2; --i) {
  //     if (profact(x / fac[i], i)) {
  //       memo[x] = true;
  //       break;
  //     }
  //   }
  // }
  return hub.find(x) != hub.end();
}

void generate(long long val, int x) {
  if (hub.find(val) != hub.end()) {
    return;
  }
  hub.insert(val);
  // cerr << val << '\n';

  int max_fac = LIM / val;
  for (int j = x; fac[j] <= LIM / val; ++ j) {
    generate(val * fac[j], j);
  }
}

void init() {
  fac[1] = 1;
  for (int i = 2; i <= 20; ++ i) {
    fac[i] = fac[i-1] * i;
  }
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  init();
  generate(1LL, 2);
  cout << hub.size() << '\n';
  // cerr << "done gen\n";

  int tc; cin >> tc;
  while (tc --) {
    long long a;
    cin >> a;
    cout << (profact(a) ? "YES\n" : "NO\n");
  }
}

// 2432902008176640000