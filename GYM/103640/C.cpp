#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 105, L = 305, INF = 1e8; 
const int xmin = 1, xmax = 301, SHIFT = 101;

// W - E - S - N
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const string dirs = "WESN";

typedef pair<int, int> Point;

char c[N];
int v[N];
vector<Point> points[N];
vector<int> tmp[L];
bool bar[L], forbid[L][L][4];
queue<Point> q;
int movingWet[L][L][4], newMovingWet[L][L][4], dist[L][L];

void processCloud(vector<Point> &points, char dirChar) {
    // update the movingWet[][][]
    // get the wet cells out!

    int dir = 0;
    while (dirs[dir] != dirChar) dir ++;

    // reset tmp
    FOR(i, xmin, xmax) tmp[i].clear();

    int start = 0;
    if (points[0].first != points[1].first) {
        start = 1;
        points.push_back(points[0]);
    }

    FOR(i, start, points.size() - 1) {
        Point point = points[i];
        tmp[point.first].push_back(point.second);
    }

    memset(bar, 0, sizeof(bar));

    FOR(x, xmin, xmax) {
        // update the bar
        FOR(i, 0, (int(tmp[x].size()) / 2 - 1)) {
            int y1 = tmp[x][2 * i], y2 = tmp[x][2 * i + 1];
            if (y1 > y2) swap(y1, y2);
            cerr << "alteranting " << x-SHIFT << " " << y1-SHIFT << ' ' << y2-1-SHIFT << '\n';
            FOR(j, y1, y2-1) {
                bar[j] = !bar[j];
            }
        }
        FOR(y, xmin, xmax) movingWet[x][y][dir] = bar[y];
    }
    cerr << "inital wet cells:\n";
    FOR(x, xmin, xmax) FOR(y, xmin, xmax) FOR(dir, 0, 3) {
        if (movingWet[x][y][dir]) cerr << x - SHIFT << " " << y - SHIFT << " " << dir << ", ";
    }
    cerr << '\n';
}

void update() {
    // update the states of edges and cells
    memset(forbid, false, sizeof(forbid));
    memset(newMovingWet, false, sizeof(newMovingWet));

    FOR(x, xmin, xmax) {
        FOR(y, xmin, xmax) {
            FOR(dir, 0, 3) {
                if (!movingWet[x][y][dir]) continue;
                
                newMovingWet[x + dx[dir]][y + dy[dir]][dir] = true;
                
                if (dir == 0) {
                    forbid[x][y+1][2] = forbid[x][y][3] = true;
                    forbid[x][y+1][1] |= movingWet[x][y+1][dir];
                    forbid[x-1][y+1][1] |= movingWet[x][y+1][dir];
                } else if (dir == 1) {
                    forbid[x+1][y+1][2] = forbid[x+1][y][3] = true;
                    forbid[x+1][y+1][0] |= movingWet[x][y+1][dir];
                    forbid[x+2][y+1][0] |= movingWet[x][y+1][dir];
                } else if (dir == 2) {
                    forbid[x][y][1] = forbid[x+1][y][0] = true;
                    forbid[x+1][y][3] |= movingWet[x+1][y][dir];
                    forbid[x+1][y-1][3] |= movingWet[x+1][y][dir];
                } else {
                    forbid[x][y+1][1] = forbid[x+1][y+1][0] = true;
                    forbid[x+1][y+1][2] |= movingWet[x+1][y][dir];
                    forbid[x+1][y+2][2] |= movingWet[x+1][y][dir];
                }
            }
        }
    }

    // FOR(x, xmin, xmax) FOR(y, xmin, xmax) FOR(dir, 0, 3) {
    //     if (forbid[x][y][dir]) cerr << "forbidding " << x << ' ' << y << ' ' << dir << '\n';
    // }
    

    FOR(x, xmin, xmax) {
        FOR(y, xmin, xmax) {
            FOR(dir, 0, 3) {
                movingWet[x][y][dir] = newMovingWet[x][y][dir];
            }
        }
    }

}

bool crossable(Point p, int dir) {
    // cerr << "checking to cross for " << p.first << ' ' << p.second << ' ' << dir << '\n';
    // based on the states, returns where the cyclist can cross the edge
    int x = p.first, y = p.second;
    // int u = min(x, x + dx[dir]), v = mnin(y, y + dy[dir]);
    // u and v are "origin" of the move
    // dir = dir / 2; // 0 is hor, 1 is ver
    return !forbid[x][y][dir];
}

bool inBoard(int x, int y) {
    return xmin <= x && xmin <= y && x <= xmax && y <= xmax;
}

int main() {
    freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    Point start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    start.first += SHIFT;
    start.second += SHIFT;
    end.first += SHIFT;
    end.second += SHIFT;
    
    int n;
    cin >> n;
    
    FOR(i, 1, n) {
        cin >> c[i] >> v[i];
        FOR(j, 1, v[i]) {
            int x, y;
            cin >> x >> y;
            points[i].push_back({x + SHIFT, y + SHIFT});
        }
        // TODO: scan this cloud!
        processCloud(points[i], c[i]);
        cerr << "done clouding\n";
    }


    FOR(x, xmin, xmax) {
        FOR(y, xmin, xmax) {
            dist[x][y] = INF;
        }
    }
    dist[start.first][start.second] = 0;
    q.push(start);

    for (int t = 1; dist[end.first][end.second] == INF; t++) {
        update();
        int sz = q.size();
        while (sz --) {
            Point p = q.front(); q.pop();
            // cerr << "popped cell: " << p.first << ' ' << p.second << '\n';
            FOR(dir, 0, 3) {
                int x = p.first + dx[dir];
                int y = p.second + dy[dir];
                if (!inBoard(x, y)) continue;
                if (crossable(p, dir) && dist[x][y] == INF) {
                    cerr << "moving to " << x-SHIFT << ' ' << y-SHIFT << " at time " << t << '\n';
                    dist[x][y] = t;
                    q.push({x, y});
                }
                q.push(p);
            }
        }
        // cerr << "done one round!\n";
    }

    cout << dist[end.first][end.second] << '\n';
}   