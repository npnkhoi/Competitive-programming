#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("B.inp", "r", stdin);
  freopen("B.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++ i) {
    int g, p; cin >> g >> p;
    cout << "Team #" << i << '\n';
    cout << "Games: " << g << '\n';
    cout << "Points: " << p << '\n';
    cout << "Possible records:\n";
    
    for (int w = min(p / 3, g); w >= 0; -- w) {
      int d = p - w * 3;
      int l = g - w - d;
      if (d >= 0 && l >= 0) {
        cout << w << '-' << d << '-' << l << '\n';
      }
    }
    if (i < n) cout << '\n';
  }
}