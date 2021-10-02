#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

pair<int, int> ran[4 * N];
set<int> bla[4 * N];
int thi[4 * N], pos[4 * N], a[N], req[N];

void init(int node, int l, int r) {
  ran[node] = {l, r};
  pos[node] = l;
  if (l < r) {
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
  }
}

void update(int node, int l, int r, int id, int thick) {
  if (l > ran[node].second || r < ran[node].first) return;
  if (l <= ran[node].first && ran[node].second <= r) {
    if (thick > 0) {
      bla[node].insert(thick);
      thi[node] += thick;
    } else {
      for (auto it = bla[node].begin(); it != bla[node].end(); ++it) {
        int bl = *it;
        req[bl] -= thick;
        if (req[bl] == 0) {
          
        }
      }
    }
    return;
  }

  update(node * 2, l, r, id, thick);
  update(node * 2 + 1, l, r, id, thick);
  int best = (thi[node * 2] > thi[node * 2 + 1] ? node * 2 : node * 2 + 1);
  thi[node] = thi[best];
  pos[node] = pos[best];
}

// void del(int p) {
//   int node = 1;
//   while (true) {
//     for (auto it = bla[node].begin(); it != bla[node].end(); it++) {
//       int tmp = it -> second;
//       if (tmp == 1) {
//         bla[node].erase(it);
//       } else {
//         bla[node][it -> first] --;
//       }
//     }
//     if (ran[node].first == ran[node].second) break;
    
//     node *= 2;
//     if (ran[node].second < p) node ++;
//   }
// }

int main() {
  int n, m; cin >> n >> m;
  init(1, 1, n);
  cerr << "check\n";
  for (int i = 0; i < m; ++ i) {
    int l, r, x;
    cin >> l >> r >> x;
    update(1, l, r, i, x);
    cerr << "update\n";
  }
  while (true) {
    if (thi[1] == 0) break;
    int tmp = pos[1];
    update(1, tmp, tmp, -1);
    a[tmp] = 1;
  }
  for (int i = 1; i <= n; ++ i) cout << a[i] << ' ';
}