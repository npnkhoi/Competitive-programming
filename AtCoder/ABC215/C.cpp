#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  sort(s.begin(), s.end());
  for (int i = 1; i < k; ++ i) {
    next_permutation(s.begin(), s.end());
  }
  cout << s;
}