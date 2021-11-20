#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

struct Point {
  long long x, y, r;
  Point() {}
  Point(long long _x, long long _y, long long _r) {
    x = _x;
    y = _y;
    r = _r;
  }
} p[N];

bool touchLeft, touchRight;
int mark[N];
vector<int> adj[N];
int n, w, l;

long long sqr(long long x) {return x * x;}

bool intersect(Point a, Point b) {
  long long dist = sqr(a.x - b.x) + sqr(a.y - b.y);
  return dist <= sqr(a.r + b.r);
}

void dfs(int u) { // need to update touchLeft and touchRight
  mark[u] = 1;
  touchLeft |= (p[u].x - p[u].r <= 0);
  touchRight |= (p[u].x + p[u].r >= w);
  for (int v: adj[u]) {
    if (!mark[v]) {
      dfs(v);
    }
  }
}

int main() {
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  int tc;
  cin >> tc;
  while (tc --) {
    cin >> n >> w >> l;
    
    // Init
    for (int i = 0; i < n; ++ i) adj[i].clear();
    memset(mark, 0, sizeof mark);
    int res = 0;

    for (int i = 0; i < n; ++ i) {
      cin >> p[i].x >> p[i].y >> p[i].r;
    }
    for (int i = 0; i < n; ++ i) {
      for (int j = i + 1; j < n; ++ j) {
        if (intersect(p[i], p[j])) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    
    for (int i = 0; i < n; ++ i) { 
      if (mark[i]) continue;
      touchLeft = touchRight = false;
      dfs(i);
      if (touchLeft && touchRight) res ++;
      // cerr << i << ' ' << res << '\n';
    }
    cout << res << '\n';
  }
}