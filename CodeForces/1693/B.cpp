#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 2e5 + 5;

int deg[N], l[N], r[N], parent[N];
long long inp[N];
int tc, n;
queue<int> q;

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  cin >> tc;
  while (tc --) {
    cin >> n;

    FOR(i, 2, n) {
      cin >> parent[i];
      deg[parent[i]] ++; 
    }
    FOR(i, 1, n) cin >> l[i] >> r[i];
    FOR(i, 1, n) if (deg[i] == 0) q.push(i);
    
    int res = 0;
    while (!q.empty()) {
      int v = q.front(); q.pop();
      if (inp[v] < l[v]) {
        res ++;
        inp[v] = r[v];
      }
      inp[parent[v]] += min(inp[v], 1LL * r[v]);
      deg[parent[v]] --;
      if (deg[parent[v]] == 0) {
        q.push(parent[v]);
      }
    }
    cout << res << '\n';

    while (!q.empty()) q.pop();
    FOR(i, 1, n) deg[i] = inp[i] = 0;
  }
}