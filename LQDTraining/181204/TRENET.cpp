#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

queue<int> q;
int dist[2 * N], m, n;
vi adj[2 * N];

bool inRow(int row, int idx) {
  return (row - 1) * (row - 1) < idx && idx <= row * row;
}

void match(int u, int v) {
  cerr << "match " << u << " " << v << "\n";
  adj[u].push_back(v);
  //adj[v].push_back(u);
}

void init() {
  for (int i = 1;; ++ i) {
    for (int idx = (i - 2) * i; idx <= i * i; ++ idx) {
      if (idx > m && idx > n) return;
      if (inRow(i, idx - 1)) match(idx, idx - 1);
      if (inRow(i, idx + 1)) match(idx, idx + 1);
      if ((i - idx) % 2 == 0) match(idx, idx + 2 * i);
      else match(idx, idx - 2 * i + 2);
    }
  }
}

void bfs() {
  memset(dist, -1, sizeof dist);
  dist[m] = 0;
  q.push(m);
  while (dist[n] == -1) {
    int u = q.front();
    q.pop();
    REP(i, adj[u].size()) {
      int v = adj[u][i];
      if (dist[v] == -1) {
        dist[v] = u;
        q.push(v);
      }
    }
  }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
  cin >> n >> m;
  init();
  bfs();
  cout << dist[n];
	return 0;
}

