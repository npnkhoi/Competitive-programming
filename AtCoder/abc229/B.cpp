#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  string a, b;
  cin >> a >> b;
  if (a.size() < b.size()) swap(a, b);
  while (a.size() > b.size()) {
    b = "0" + b;
  }
  int n = a.size();
  bool hard = false;
  FOR(i, 1, n) {
    int x = a[a.size() - i] - '0';
    int y = b[b.size() - i] - '0';
    if (x + y >= 10) hard = true;   
  }
  cout << (hard ? "Hard" : "Easy");
}