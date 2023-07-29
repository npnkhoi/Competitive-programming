#include <bits/stdc++.h>

using namespace std;
const int MAX = 1050, N = 1e3 + 3;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};
typedef pair<int, int> pii;

int mark[N][N], depth[N], matrixA[MAX][MAX], matrixB[MAX][MAX];
pii mapLocationA[MAX * MAX], mapLocationB[MAX * MAX];
int main() {
    freopen("Test.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrixA[i][j];
            mapLocationA[matrixA[i][j]] = {i, j};
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrixB[i][j];
            mapLocationB[matrixB[i][j]] = {i, j};
        }
    }

    int res = 0, cc = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if (!mark[i][j]) {

            int currentA = matrixA[i][j];
            pii posB = mapLocationB[currentA];
            queue <pii> q;
            while (!q.empty()) q.pop();
            q.push({i, j});
            cc++;

            cerr << i << ' ' << j << ' ' << posB.first << ' ' << posB.second << endl;

            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                mark[x][y] = cc;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dr[i], ny = y + dc[i];
                    if (nx == -1 || nx == n || ny == -1 || ny == m) {
                        continue;
                    }
                    cerr << "    " << nx << ' ' << ny << ' ' << matrixB[posB.first + nx - i][posB.second + ny - j] << endl;
                    if (!mark[nx][ny] && (matrixA[nx][ny] == matrixB[posB.first + nx - i][posB.second + ny - j])) {
                        q.push({nx, ny});
                        mark[nx][ny] = cc;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << mark[i][j] << ' ';
        }
        cout << endl;
    }

    cout << res << endl;



    return 0;
}
