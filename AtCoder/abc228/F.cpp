#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int a[N][N];
long long s[N][N], b[N][N], maxRow[N][N], maxSquare[N][N];

long long sum(int r1, int c1, int r2, int c2) {
  return s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int h, w, h1, w1, h2, w2;
  cin >> h >> w >> h1 >> w1 >> h2 >> w2;
  for (int i = 1; i <= h; ++ i) {
    for (int j = 1; j <= w; ++ j) {
      cin >> a[i][j];
      s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    }
  }
  h2 = min(h2, h1);
  w2 = min(w2, w1);
  for (int i = 1; i + h2 - 1 <= h; ++ i) {
    for (int j = 1; j + w2 - 1 <= w; ++ j) {
      b[i][j] = sum(i, j, i+h2-1, j+w2-1);
      // cerr << b[i][j] << ' ';
    }
    // cerr << '\n';
  }
  // cerr << '\n';
  // Work on b
  int h3 = h1-h2+1, w3 = w1-w2+1;
  int hb = h - h2 + 1, wb = w - w2 + 1;
  for (int i = 1; i <= hb; ++ i) {
    deque<int> q;
    for (int j = 1; j <= wb; ++ j) {
      while (!q.empty() && b[i][q.back()] <= b[i][j]) q.pop_back();
      q.push_back(j);
      if (q.front() <= j - w3) q.pop_front();
      maxRow[i][j] = b[i][q.front()];
      // cerr << maxRow[i][j] << ' ';
    }
    // cerr << '\n';
  }
  // cerr << '\n';
  for (int j = w3; j <= wb; ++ j) {
    deque<int> q;
    for (int i = 1; i <= hb; ++ i) {
      while (!q.empty() && maxRow[q.back()][j] <= maxRow[i][j]) q.pop_back();
      q.push_back(i);
      if (i > h3 && q.front() <= i - h3) q.pop_front();
      maxSquare[i][j] = maxRow[q.front()][j];
      // cerr << maxSquare[i][j] << ' ';
    }
    // cerr << '\n';
  }
  // cerr << '\n';
  // Find result
  // cerr << '\n';
  long long res = 0;
  for (int i = h3; i <= hb; ++ i) {
    for (int j = w3; j <= wb; ++ j) {
      int realRow = i + h2 - 1, realCol = j + w2 - 1;
      if (realRow < h1 || realCol < w1) continue;
      long long black = sum(realRow-h1+1, realCol-w1+1, realRow, realCol);
      long long white = maxSquare[i][j];
      // cerr << white << ' ';
      res = max(res, black - white);
    }
    // cerr << '\n';
  }
  cout << res;
}