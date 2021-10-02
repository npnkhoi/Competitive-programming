#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n; cin >> n;
  vector<int> v;

  while (n) {
    v.push_back(n%2);
    n /= 2;
  }

  for (int i = v.size() - 1; i >= 0; --i) {
    if (v[i]) cout << 'A';
    if (i > 0) cout << 'B';
  }
}