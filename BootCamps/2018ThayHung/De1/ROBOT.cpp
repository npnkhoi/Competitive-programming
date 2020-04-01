#include <utility>
#include <vector>
#include <stdio.h>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) for (int i = 0; i < n; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)

#define task "ROBOT"
struct pack {
    int x, y, d, t;
};
const int N = 1005;
const int D = 6;
const int T = 3;

const int oo = 1e8 + 9;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

queue<pack> q;
int a[N][N], f[N][N][D][T], g[N][N][D][T];
int n, X1, X2, Y1, Y2, res1, res2, cnt;

bool inside(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}
pack mPack(int x, int y, int d, int t) {
    pack tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.d = d;
    tmp.t = t;
    return tmp;
}
void pushQueue(int x, int y, int d, int t, int l, int f[][N][D][T]) {
    //printf("push queue %d %d %d %d %d\n", x, y, d, t, l);
    if (f[x][y][d][t] != oo) return;
    //printf("push queue %d %d %d %d %d\n", x, y, d, t, l);
    f[x][y][d][t] = l;
    q.push(mPack(x, y, d, t));
    //printf("%d %d %d %d -> %d\n", x, y, d, t, l);

    while (1) {
        x += dx[d];
        y += dy[d];
        if (inside(x, y)) {
            if (a[x][y] == 0) {
                if (f[x][y][d][t] == oo) {
                    f[x][y][d][t] = l;
                    q.push(mPack(x, y, d, t));
                    //printf("%d %d %d %d -> %d\n", x, y, d, t, l);
                } else break;
            } else {
                if (t == 0 && f[x][y][d][1] == oo)
                    pushQueue(x, y, d, 1, l, f);
                break;
            }
        } else break;
    }
}
void flood(int x, int y, int f[][N][D][T]) {
    //printf("flood %d %d\n", x, y);
    FOR(i, 1, n) FOR(j, 1, n) FOR(d, 0, 3) FOR(t, 0, 1) f[i][j][d][t] = oo;
    while (!q.empty()) q.pop();

    REP(_d, 4) pushQueue(x, y, _d, 0, 0, f);

    while (!q.empty()) {
        int xx = q.front().x;
        int yy = q.front().y;
        int dd = q.front().d;
        int tt = q.front().t;
        q.pop();
        int l = f[xx][yy][dd][tt];
        REP(_d, 4) if (f[xx][yy][_d][tt] == oo)
        pushQueue(xx, yy, _d, tt, l + 1, f);
    }
    //FOR(i, 1, n) FOR(j, 1, n) FOR(d, 0, 3) FOR(t, 0, 1)
    //printf("f(%d, %d, %d, %d) = %d\n", i, j, d, t, f[i][j][d][t]);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &a[i][j]);
    scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);

    flood(X1, Y1, f);
    flood(X2, Y2, g);

    res1 = res2 = oo;
    cnt = 0;

    REP(_d, 4) {
        res1 = min(res1, f[X2][Y2][_d][0]);
        res2 = min(res2, min(res1, f[X2][Y2][_d][1]));
    }
    if (res2 == res1)
        FOR(i, 1, n) FOR(j, 1, n) cnt += a[i][j];
    else
        FOR(x, 1, n) FOR(y, 1, n) if (a[x][y]) {
            int tmp = oo;
            FOR(_d, 0, 3)
                tmp = min(tmp, f[x][y][_d][1] + g[x][y][3 - _d][1]);
            cnt += (tmp == res2);
        }
    printf("%d %d %d", res1, res2, cnt);
    return 0;
}
