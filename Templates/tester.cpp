/*
Tester
- Input: test.inp
- Code: NAME, NAME_bf
- Output: , test.out , test.ans
- RAND_MAX is around 2^31 - 1
*/

#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const string NAME = "Template";
const int NUM_TEST = 100;

void gen() {
  ofstream inp("test.inp");
  // Write your input here (inp << ...)

  inp.close();
}

int main() {
  srand(time(NULL));
  FOR(i, 1, NUM_TEST) {
    gen();
    system(("./" + NAME).c_str());
    system(("./" + NAME + "_bf").c_str());
    if (system("diff test.out test.ans")) {
      cerr << "ERORR FOUND!!\n";
      return 0;
    }
    cerr << "Done test " << i << '\n';
  }
  cerr << "PASS\n";
}