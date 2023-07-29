#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 500000 + 2;

int s[N];

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  string x;
  cin >> x;
  int n = x.size();
  long long tmp = 0;
  FOR(i, 0, n-1) {
    tmp += x[i] - '0';
    s[i] = tmp;
  }
  string res = "";
  tmp = 0;
  FORD(i, n-1, 0) {
    tmp += s[i];
    res += char(tmp % 10 + '0');
    tmp = tmp / 10;
  }
  while (tmp) {
    res += char(tmp % 10 + '0');
    tmp = tmp / 10;
  }
  reverse(res.begin(), res.end());
  cout << res;
}