#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int N = 105;

int h, w, vis[N][N];
string s[N];

bool inBoard(int r, int c) {
  return 0 <= r && r < h && 0 <= c && c < w;
}

void dfs(int r, int c) {
  vis[r][c] = 1;
  for (int dir = 0; dir < 4; ++ dir) {
    int u = r + dx[dir], v = c + dy[dir];
    if (inBoard(u, v) && !vis[u][v] && s[u][v] == '-') {
      dfs(u, v);
    }
  }
}

int main() {
  int case_id = 0;
  while (cin >> h) {
    case_id ++;
    cin >> w;
    for (int i = 0; i < h; ++ i) {
      cin >> s[i];
    }
    memset(vis, 0, sizeof vis);
    int res = 0;
    for (int i = 0; i < h; ++ i) {
      for (int j = 0; j < w; ++ j) {
        if (s[i][j] == '-' && !vis[i][j]) {
          dfs(i, j);
          res ++;
        }
      }
    }
    printf("Case %d: %d\n", case_id, res);
  }
}