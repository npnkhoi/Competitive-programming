#include <bits/stdc++.h>
using namespace std;

const int N = 405, INF = 1e9;

int dist[N][N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      dist[i][j] = (i == j ? 0 : INF);
    }
  }
  long long res = 0, currSum = 0;
  for (int i = 0; i < m; ++ i) { 
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = c;
    currSum += c;
  }
  for (int k = 1; k <= n; ++ k) {
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= n; ++ j) {
        int newDist = dist[i][k] + dist[k][j];
        if (newDist < dist[i][j]) {
          if (dist[i][j] == INF) {
            currSum += newDist;
          } else {
            currSum += newDist - dist[i][j];
          }
          dist[i][j] = newDist;
        }
      }
    }
    res += currSum;
  }
  cout << res;
}