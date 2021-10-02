#include <bits/stdc++.h>
using namespace std;

const int N = 26, INF = 1e9 + 7;
const string VOWELS = "UEOAI";

int e[N][N];
string s, t;

int main() {
  freopen("inp.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int tc; cin >> tc;
  int n = 26, m;

  // Pre-calculation
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      e[i][j] = (i == j ? 0 : INF);
    }
  }

  for (int i = 0; i < 5; ++ i) {
    for (int j = 0; j < 26; ++ j) {
      if (VOWELS.find(char(j + 'A')) != -1) continue;
      int c = VOWELS[i] - 'A';
      e[c][j] = e[j][c] = 1;
    }
  }   

  for (int k = 0; k < n; ++ k) {
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < n; ++ j) {
        e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
      }
    }
  }
  
  for (int itest = 1; itest <= tc; ++itest) {
    cin >> s;
    
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