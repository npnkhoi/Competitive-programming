using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

const int N = 5e3 + 20;
const int oo = 1e9 + 7;

int n, m, s;
long long cnt[N];
vector< pair<int, int> > adj[N];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
int dist[N];

int main() {
    freopen("obinh.inp", "r", stdin);
    freopen("obinh.out", "w", stdout);
    scanf("%d %d", &n ,&m);
    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }

    for (int i = 1; i <= n; i++) dist[i] = oo; dist[1] = 0;
    cnt[1] = 1LL;
    pq.push(make_pair(0, 1));

    while (!pq.empty()) {
        pair<int, int> t = pq.top(); pq.pop();
        int d = t.first, u = t.second;
        if (d > dist[u]) continue;

        for (int i = 0; i < adj[u].size(); i++) {
            pair<int, int> v = adj[u][i];
            if (dist[v.first] > dist[u] + v.second) {
                cnt[v.first] = cnt[u];
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
            else if (dist[v.first] == (dist[u] + v.second))
                cnt[v.first] += cnt[u];
        }
    }
    printf("%d %lld", dist[n], cnt[n]);
}
