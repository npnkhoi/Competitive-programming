#include <bits/stdc++.h>
using namespace std;

const int N = 26, INF = 1e9 + 7;

int e[N][N];
string s, t;

int main() {
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int tc; cin >> tc;
  int n = 26, m;
  
  for (int itest = 1; itest <= tc; ++itest) {
    // TODO: reset
    // cerr << "hello\n";
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < n; ++ j) {
        e[i][j] = (i == j ? 0 : INF);
      }
    }
    // cerr << "hello\n";
    cin >> s >> m;
    for (int i = 0; i < m; ++ i) {
      string edge; cin >> edge;
      e[edge[0] - 'A'][edge[1] - 'A'] = 1;
      // cerr << "adding edge " << edge[0] - 'A' << ' ' << edge[1] - 'A' << '\n';
    }

    // cerr << "hello\n";

    for (int k = 0; k < n; ++ k) {
      for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
          e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
        }
      }
    }


    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < n; ++ j) {
        // cerr << e[i][j] << ' ';
      }
      // cerr << '\n';
    }


    int res = INF;
    for (int c = 0; c < n; ++ c) {
      int dist = 0;
      for (int i = 0; i < s.size(); ++ i) {
        int tmp = e[s[i] - 'A'][c];
        if (tmp == INF) {
          dist = -1;
          break;
        } else {
          dist += tmp;
        }
      }
      if (dist != -1) res = min(res, dist);
    }
    cout << "Case #" << itest << ": " << (res == INF ? -1 : res) << '\n';
  }
}