using namespace std;
#include <stdio.h>
#include <set>
#include <vector>

const int N = 1e5 + 10;
typedef pair<int, int> ii;
int n, m, k;
vector<int> adj[N];
int adjN[N];
set<ii> data;
set<ii> edge;
int main () {
    freopen("hfamous.inp", "r", stdin);
    freopen("hfamous.out", "w", stdout);
    scanf("%d %d %d", &n ,&m, &k);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (v>u) swap(u, v);
        if (edge.find(ii(u, v))!= edge.end()) continue;
        if (u == v) continue;
        edge.insert(ii(u, v));
        adj[u].push_back(v);
        adj[v].push_back(u);
        adjN[u] ++;
        adjN[v] ++;
    }
    for (int i = 1; i <= n; i++) data.insert(ii(adjN[i], i));

    while ( (!data.empty()) && (data.begin()-> first) < k) {
        int u = data.begin() -> second;
        adjN[u] = -1;
        data.erase(data.begin());
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (adjN[v] == -1) continue;
            data.erase(ii(adjN[v], v));
            adjN[v] --;
            data.insert(ii(adjN[v], v));
        }
    }
    printf("%d\n",data.size());
}
