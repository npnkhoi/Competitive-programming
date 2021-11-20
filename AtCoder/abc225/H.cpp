#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
// typedef pair<long long, pair<int, int>> Pack;
typedef pair<int, int> Pack;

long long a[N][N], pot[N][N], mark[N][N], nxt[2][N][N];
queue<Pack> q;
int h, w, cost;
long long res = 0;

void update(int r, int c, int type) {
  if (r < 1 || r > h || c < 1 || c > w) return;
  if (nxt[type][r][c]) return;
  nxt[type][r][c] = 1;
  pot[r][c] -= cost;
  if (pot[r][c] >= 0) {
    q.push({r, c});
  }
}

void add(int r, int c) {
  if (mark[r][c]) return;
  res += pot[r][c];
  mark[r][c] = 1;
  update(r-1, c-1, 0);
  update(r+1, c+1, 0);
  update(r-1, c+1, 1);
  update(r+1, c-1, 1);
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  
  cin >> h >> w >> cost;
  for (int i = 1; i <= h; ++ i) {
    for (int j = 1; j <= w; ++ j) {
      cin >> a[i][j];
      pot[i][j] = a[i][j] - 2*cost;
      if (pot[i][j] >= 0) 
        q.push({i, j});
    }
  }
  
  while (!q.empty()) {
    Pack t = q.front(); q.pop();
    int r = t.first, c = t.second;
    add(r, c);
  }
}