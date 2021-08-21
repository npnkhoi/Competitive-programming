#include <bits/stdc++.h>
using namespace std;

const int N = 505, INF = 1e9+7;
const int shiftX[] = {0, 0, -1, 1};
const int shiftY[] = {-1, 1, 0, 0};
typedef pair<int, int> Pack;

int h, w, mark[N][N];
string a[N];
queue<Pack> q;

bool inBoard(int x, int y) {
    return 0 <= x && x <= h && 0 <= y && y < w;
}

void dfs(int i, int j, int dist) {
    // printf("dfs %d %d (id = %d)\n", i, j, nodes);
    mark[i][j] = dist;
    q.push({i, j});

    // vis, borders to queue, with cc_id
    for (int dir = 0; dir < 4; ++ dir) {
        int u = i + shiftX[dir], v = j + shiftY[dir];
        if (inBoard(u, v) && mark[u][v] == -1 && a[u][v] == '.') {
            dfs(u, v, dist);
        }
    }
}

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; ++ i) {
        cin >> a[i];
    }

    memset(mark, -1, sizeof mark);
    
    dfs(0, 0, 0);

    while (!q.empty()) {
        Pack u = q.front(); q.pop();
        int i = u.first, j = u.second;
        for (int x = i - 2; x <= i + 2; ++ x) {
            int dy = (abs(x-i) == 2 ? 1 : 2);
            for (int y = j - dy; y <= j + dy; ++ y) {
                if (!inBoard(x, y) || mark[x][y] != -1) continue;
                
                dfs(x, y, mark[i][j] + 1);
                
            }
        }
    }
    
    cout << mark[h-1][w-1];
}