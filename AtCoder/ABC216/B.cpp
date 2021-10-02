#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

string s[N], t[N];

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; ++ i) {
    cin >> s[i] >> t[i];
  }
  for (int i = 0; i < n; ++ i) {
    for (int j = i + 1; j < n; ++ j) {
      if (s[i] == s[j] && t[i] == t[j]) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}