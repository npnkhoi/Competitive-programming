#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

void gen() {
  ofstream inp("test.inp");
  int T = 5;
  inp << T << '\n';
  FOR(t, 1, T) {
    int n = 1 + rand() % 20;
    int u = 1 + rand() % 100;
    int m = 1 + rand() % 100;
    inp << n << ' ' << u << ' ' << m << '\n';
    FOR(i, 1, n) {
      int w = 1 + rand() % 100;
      inp << w << ' ';
    }
    inp << '\n';
  }
  inp.close();
}

int main() {
  srand(time(NULL));
  FOR(i, 1, 1000) {
    gen();
    system("./F");
    system("./F_bf");
    if (system("diff test.out test.ans")) {
      cerr << "ERORR FOUND!!\n";
      return 0;
    }
    cerr << "Done test " << i << '\n';
  }
  cerr << "PASS\n";
}