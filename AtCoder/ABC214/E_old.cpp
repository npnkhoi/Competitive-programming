#include <bits/stdc++.h>
using namespace std;

// vector<pair<int, int>> v;
map<int, int> delta[2];
set<int> events;

void add(int x, int id) {
  if (delta[id].find(x) == delta[id].end()) {
    delta[id][x] = 0;
  }
  delta[id][x] ++;
}

void update(int x, int d) {
  if (d < 0) {
    // start
    events.insert(x - 1);
    events.insert(x);
    add(x, 0);
  } else {
    events.insert(x);
    add(x, 1);
  }
}

int main() {
  int tc; cin >> tc;
  while (tc --) {
    int n; cin >> n;
    
    delta[0].clear();
    delta[1].clear();
    events.clear();

    for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      update(l - 1, -1);
      update(r, +1);
    }

    bool ans = true;    
    int started = 0, ended = 0, mxx = -1e9;
    for (auto x : events) {
      if (x - ended < mxx) {
        ans = false;
        printf("break at %d\n", x);
        break;
      }
      if (delta[0].find(x) != delta[0].end()) {
        cerr << "updating .. \n";
        started += delta[0][x];
      }
      mxx = max(mxx, x + 1 - started);
      if (delta[1].find(x) != delta[1].end()) {
        cerr << "updating .. \n";
        ended += delta[1][x];
      }
      printf("status at %d: %d %d\n", x, started, ended);
    }
    cout << (ans ? "Yes" : "No") << '\n';
  }
}