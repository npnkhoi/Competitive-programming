#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 1005;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int dist[N][N];
queue<pair<int, int>> q;

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int r, c, n;
    cin >> r >> c >> n;
    memset(dist, -1, sizeof dist);
    FOR(i, 1, n) {
        int x, y;
        cin >> x >> y;
        if (dist[x][y] == -1) {
            dist[x][y] = 1;
            q.push({x, y});
        }
    }

    int res = 1;
    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        FOR(dir, 0, 3) {
            int u = cell.first + dx[dir];
            int v = cell.second + dy[dir];
            if (1 <= u && u <= r && 1 <= v && v <= c && dist[u][v] == -1) {
                dist[u][v] = dist[cell.first][cell.second] + 1;
                res = dist[u][v];
                q.push({u, v});
            }
        }
    }
    cout << res;
}