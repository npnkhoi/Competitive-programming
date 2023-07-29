#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

void gen() {
  ofstream inp("test.inp");
  int n = 1e6;
  inp << n << '\n';
  FOR(i, 1, n) {
    int x = rand() % int(2e9) - 1e9;
    int y = rand() % int(2e9) - 1e9;
    inp << x << ' ' << y << '\n';
  }
  inp.close();
}

int main() {
  srand(time(NULL));
  gen();
}