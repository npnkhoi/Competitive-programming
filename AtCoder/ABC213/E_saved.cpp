#include <bits/stdc++.h>
using namespace std;

const int N = 505, INF = 1e9+7;
const int shiftX[] = {0, 0, -1, 1};
const int shiftY[] = {-1, 1, 0, 0};
typedef pair<int, int> Pack;

int h, w, mark[N][N], id[N][N], nodes, dist[N*N];
string a[N];
queue<Pack> q;
vector<Pack> adj[N*N];
priority_queue<Pack, vector<Pack>, greater<Pack>> pq;

bool inBoard(int x, int y) {
    return 0 <= x && x <= h && 0 <= y && y < w;
}

void dfs(int i, int j) {
    // printf("dfs %d %d (id = %d)\n", i, j, nodes);
    id[i][j] = nodes;
    q.push({i, j});

    // vis, borders to queue, with cc_id
    for (int dir = 0; dir < 4; ++ dir) {
        int u = i + shiftX[dir], v = j + shiftY[dir];
        if (inBoard(u, v) && id[u][v] == -1 && a[u][v] == '.') {
            dfs(u, v);
        }
    }
}

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; ++ i) {
        cin >> a[i];
    }

    memset(id, -1, sizeof id);
    for (int i = 0; i < h; ++ i) {
        for (int j = 0; j < w; ++ j) {
            if (id[i][j] == -1 && a[i][j] == '.') {
                dfs(i, j);
                nodes ++;
            }
        }
    }

    // flood fill
    while (!q.empty()) {
        Pack u = q.front(); q.pop();
        for (int x = u.first - 2; x <= u.first + 2; ++ x) {
            int dy = (abs(x-u.first) == 2 ? 1 : 2);
            for (int y = u.second - dy; y <= u.second + dy; ++ y) {
                if (!inBoard(x, y)) continue;

                // printf("visiting %d %d\n", x, y);

                if (id[x][y] == -1) {
                    mark[x][y] = mark[u.first][u.second] + 1;
                    id[x][y] = id[u.first][u.second];
                    q.push({x, y});
                } else if (id[x][y] != id[u.first][u.second] && abs(x - u.first) + abs(y - u.second) == 1) {
                    int node1 = id[x][y];
                    int node2 = id[u.first][u.second];
                    int weight = mark[x][y] + mark[u.first][u.second];
                    adj[node1].push_back({node2, weight});
                    adj[node2].push_back({node1, weight});
                    // printf("new edge: %d %d %d\n", node1, node2, weight);
                    // printf("(%d, %d, %d) -> (%d, %d, %d)", x, y, mark[x][y], u.first, u.second, mark[u.first][u.second]);
                }
            }
        }
    }

    // find the path from id[0][0] to id[h][w]; dijkstra
    int s = id[0][0];
    int t = id[h-1][w-1];

    for (int i = 0; i < nodes; ++ i) {
        dist[i] = INF;
    }
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        pair<int, int> u = pq.top(); pq.pop();
        for (Pack v : adj[u.second]) {
            if (dist[v.first] > u.first + v.second) {
                dist[v.first] = u.first + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
    
    cout << dist[t];
}