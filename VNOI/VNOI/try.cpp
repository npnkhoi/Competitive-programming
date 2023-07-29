#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int start = clock();
  bitset<2> bs;
  bs[0] = true;
  cout << (bs) << '\n';
  cout << (bs << 1) << '\n';
  cout << (bs << 2) << '\n';
  cerr << (clock() - start) / CLOCKS_PER_SEC;
}