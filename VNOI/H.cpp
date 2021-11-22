#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;
typedef pair<long long, unsigned long long> Pack;

const int md = 1e9 + 7;

int n, m, d;
set<Pack> s;

Pack newSeq(Pack seq, int c) {
  seq.first = (seq.first * 256 + c) % md;
  seq.second = seq.second * 256 + c;
  return seq;
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  cin >> n >> m >> d;
  FOR(i, 1, n) {
    Pack hash = {0, 0};
    FOR(j, 0, d) {
      int x;
      cin >> x;
      hash = newSeq(hash, x);
    }
    s.insert(hash);
  }
  FOR(i, 1, m) {
    Pack hash = {0, 0};
    FOR(j, 0, d) {
      int x;
      cin >> x;
      hash = newSeq(hash, x);
    }
    cout << (s.find(hash) != s.end() ? "BAD" : "GOOD") << '\n';
  }
}