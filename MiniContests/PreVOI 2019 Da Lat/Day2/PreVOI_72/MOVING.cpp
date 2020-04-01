#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <bitset>
#include <complex>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < n; ++i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,b,a) for (int i = b; i >= a; --i)

#define all(v) v.begin(), v.end()
#define debug(a) cerr << #a << " = " << a << "\n"

#define task "MOVING"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int oo = 1e9 + 7, N = 1905;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int tc, n, m, s, t, flow;
int e[N][N], trace[N];
queue<int> q;
vi adj[N];

int id(int i, int j) {
  return m * (i - 1) + j;
}

void addEdge(int u, int v, int c) {
  //cerr << "add " << u << ' ' << v << ' ' << c << '\n';
  adj[u].push_back(v);
  e[u][v] += c;
  /// - ?
}

bool inBoard(int x, int y) {
  return 1 <= x && x <= n && 1 <= y && y <= m;
}

void buildNet() {
  int x;
  FOR(i, 1, n) {
    FOR(j, 1, m) {
      cin >> x;
      if (x > 0) addEdge(s, id(i, j), 1);
    }
  }
  FOR(i, 1, n) {
    FOR(j, 1, m) {
      cin >> x;
      if (x > 0) addEdge(id(i, j), t, 1);
    }
  }
  FOR(i, 1, n) {
    FOR(j, 1, m) {
      cin >> x;
      REP(dir, 4) {
        int u = i + dx[dir], v = j + dy[dir];
        if (!inBoard(u, v)) continue;
        addEdge(id(u, v), id(i, j) + m * n, x);
      }
      addEdge(id(i, j) + m * n, id(i, j), x);
    }
  }
}

bool findPath() {
  while (!q.empty()) q.pop();
  memset(trace, -1, sizeof trace);
  q.push(s); trace[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    REP(i, adj[u].size()) {
      int v = adj[u][i];
      if (trace[v] == -1 && e[u][v] > 0) {
        trace[v] = u;
        if (v == t) return 1;
        q.push(v);
      }
    }
  }
  return 0;
}

void augment() {
  int u = t;
  int minEdge = oo;
  while (u != s) {
    minEdge = min(minEdge, e[trace[u]][u]);
    u = trace[u];
  }
  flow += minEdge;
  u = t;
  while (u != s) {
    e[trace[u]][u] -= minEdge;
    e[u][trace[u]] += minEdge;
    u = trace[u];
  }
}

void maxFlow() {
  flow = 0;
  while (findPath()) augment();
}

int main() {
  ios::sync_with_stdio();
  cin.tie(0); cout.tie(0);
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);
  cin >> tc;
  while (tc --) {
    /// delete graph
    cin >> n >> m;
    s = 0, t = 2*m*n+1;
    FOR(i, 0, 2*m*n+1) adj[i].clear();
    memset(e, 0, sizeof e);

    buildNet();
    maxFlow();
    cout << flow << '\n';
  }
}
