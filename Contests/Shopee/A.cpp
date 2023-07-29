#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int HOLES = 300, N = 1005, INF = 1e9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

stack<pair<int, int>> pos[HOLES];
int a[N][N], mark[N][N], dist[N][N];
queue<pair<int, int>> q;

void myPush(int i, int j) {
    q.push({i, j});
    mark[i][j] = 1;
    if (a[i][j] != 0) {
        while (!pos[a[i][j]].empty()) {
            pair<int, int> cell = pos[a[i][j]].top();
            pos[a[i][j]].pop();
            if (!mark[cell.first][cell.second]) {
                mark[cell.first][cell.second] = 1;
                dist[cell.first][cell.second] = dist[i][j];
                myPush(cell.first, cell.second);                
            }
        }
    }
}

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int m, n;
    cin >> m >> n;
    FOR(i, 1, m) {
        FOR(j, 1, n) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                pos[a[i][j]].push({i, j});
            }
        }
    }
    
    FOR(i, 1, m) FOR(j, 1, n) dist[i][j] = INF;
    dist[1][1] = 0;
    myPush(1, 1);
    while (!q.empty()) {
        pair<int, int> cell = q.front(); q.pop();
        FOR(dir, 0, 3) {
            int u = cell.first + dx[dir];
            int v = cell.second + dy[dir];
            if (1 <= u && u <= m && 1 <= v && v <= n && !mark[u][v]) {
                dist[u][v] = dist[cell.first][cell.second] + 1;
                myPush(u, v);
            }
        }
    }
    // FOR(i, 1, m) {
    //     FOR(j, 1, n) {
    //         cerr << mark[i][j] << ' ';
    //     }
    //     cerr << '\n';
    // }
    // FOR(i, 1, m) {
    //     FOR(j, 1, n) {
    //         cerr << dist[i][j] << ' ';
    //     }
    //     cerr << '\n';
    // }

    cout << dist[m][n];
}