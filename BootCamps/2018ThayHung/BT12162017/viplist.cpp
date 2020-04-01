#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define task "viplist"

const int N = 1e5 + 5;
int n, m, k, cnt;
int deg[N];
bool del[N];
vector<int> adj[N];
queue<int> q;

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        deg[x] ++; deg[y] ++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] < k) {
            q.push(i);
            del[i] = 1;
            cnt ++;
        }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (!del[v]) {
                deg[v] --;
                if (deg[v] < k) {
                    q.push(v);
                    cnt ++;
                    del[v] = 1;
                }
            }
        }
    }
    printf("%d\n", n - cnt);
    for (int i =1; i <= n; ++i) if (!del[i]) printf("%d ", i);
}
