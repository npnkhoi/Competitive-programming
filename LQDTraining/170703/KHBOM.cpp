using namespace std;
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <set>

typedef pair<int, int> ii;
const int N = 1e5 + 50;
const int inf = 1e9;
int n, m, p, t;
set<int> A;
vector<int> B;
long long dist[N];
vector<pair<int, int> > adj[N];
int main() {
    freopen("KHBOM.inp", "r",stdin);
    freopen("KHBOM.out", "w",stdout);
    scanf("%d %d %d %d", &n ,&m, &p, &t);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        A.insert(x);
    }
    for (int i = 1; i <= m; i ++) {
        int x;
        scanf("%d", &x);
        B.push_back(x);
    }

    while (t--) {
        int u, v;
        long long c;
        scanf("%d %d %d", &u, &v, &c);
        if (A.find(u) != A.end()) u = 0;
        if (A.find(v) != A.end()) v = 0;
        if (u != v) {
            adj[u].push_back(make_pair(v, c));
            adj[v].push_back(make_pair(u, c));
        }
    }
    vector<int> dist(N, inf); dist[0] = 0;                  // INF = 1B to avoid overflow
    priority_queue< ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, 0));
                             // ^to sort the pairs by increasing distance from s
    while (!pq.empty()) {                                             // main loop
        ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;   // this check is important, see the explanation
        for (int j = 0; j < (int)adj[u].size(); j++) {
            ii v = adj[u][j];                       // all outgoing edges from u
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;                 // relax operation
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    int res = inf;
    for (int i = 0; i < m; i++) res = min(res, dist[B[i]]);
    cout << res;
}
