#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  string s1, s2;
  cin >> s1 >> s2;
  if ((s1 == "#." && s2 == ".#") or (s2 == "#." && s1 == ".#")) {
    cout << "No";
  } else {
    cout << "Yes";
  }
}