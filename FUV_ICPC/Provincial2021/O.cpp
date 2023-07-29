#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 2e5 + 5;

long long res = 0;
int n, x, y;
map<int, int> cntX, cntY;
map<pair<int, int>, int>cntP;
set<pair<int, int>> p;

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  cin >> n;
  FOR(i, 1, n) {
    cin >> x >> y;
    if (p.find({x, y}) != p.end()) 
    p.insert({x, y});
    if (cntX.find(x) == cntX.end()) {
      cntX[x] = 0;
    }
    if (cntY.find(x) == cntY.end()) {
      cntY[x] = 0;
    }
    if (cntP.find({x, y}) == cntP.end()) {
      cntP[{x, y}] = 0;
    }
    res += cntX[x] + cntY[y] - cntP[{x, y}];
    cntX[x] ++;
    cntY[y] ++;
    cntP[{x, y}] ++;
  }
  cout << res;
}