using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp(".inp");
//ofstream out(".out");
const int N = 105;
const int oo = 1e9 + 7;
struct pack {
    int i, j, x;
};
int d1i[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int d1j[] = {1, -1, 2, -2, 2, -2, 1, -1};
int d2i[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int d2j[] = {-1, 0, 1, -1, 1, -1, 0, 1};
pack Pack(int i, int j, int x) {
        pack tmp;
        tmp.i = i;
        tmp.j = j;
        tmp.x = x;
        return tmp;
    }

int m, n;
int a[N][N], d1[N][N][3], d2[N][N][3];
queue<pack> q;

bool ok(int i, int j) {
    return a[i][j] != '#' &&
        i >= 1 && i <= m && j >= 1 && j <= n;
}
int main() {
    freopen("MATOT.inp", "r", stdin);
    freopen("MATOT.out", "w", stdout);
    scanf("%d%d", &m, &n);

    int mi, mj, ti, tj;

    FOR(i, 1, m) FOR(j, 1, n) {
        scanf(" %c", &a[i][j]);
        if (a[i][j] == 'M')
            mi = i, mj = j;
        else if (a[i][j] == 'T')
            ti = i, tj = j;
    }

    memset(d1, -1, sizeof d1); d1[mi][mj][0] = 0;
    q.push(Pack(mi, mj, 0));
    bool move1 = 0;
    while (!q.empty()) {
        pack tmp = q.front(); q.pop();
        REP(z, 8) {
            int u = tmp.i + d1i[z];
            int v = tmp.j + d1j[z];
            int x = tmp.x ^ 1;
            if (ok(u, v) && d1[u][v][x] == -1) {
                q.push(Pack(u, v, x));
                //printf("%d %d %d\n", u, v, x);
                d1[u][v][x] = d1[tmp.i][tmp.j][tmp.x] + 1;
                //printf("d1[%d][%d][%d] = %d\n", u, v, x, d1[u][v][x]);
                move1 = 1;
            }
        }
    }
    //cerr << "\n";

    bool move2 = 0;
    memset(d2, -1, sizeof d2); d2[ti][tj][0] = 0;
    q.push(Pack(ti, tj, 0));
    while (!q.empty()) {
        pack tmp = q.front(); q.pop();
        //printf("new: %d %d %d\n", tmp.i, tmp.j, tmp.x);
        REP(z, 8) {
            int u = tmp.i + d2i[z];
            int v = tmp.j + d2j[z];
            int x = tmp.x ^ 1;
            //printf("? %d %d %d\n", u, v, x);
            if (ok(u, v) && d2[u][v][x] == -1) {
                q.push(Pack(u, v, x));
                //printf("-> %d %d %d\n", u, v, x);
                d2[u][v][x] = d2[tmp.i][tmp.j][tmp.x] + 1;
                //printf("d2[%d][%d][%d] = %d\n", u, v, x, d2[u][v][x]);
                move2 = 1;
            }
        }
    }

    int res = oo;
    FOR(i, 1, m) FOR(j, 1, n) FOR(x, 0, 1)
        if (d1[i][j][x] != -1 && d2[i][j][x] != -1)
        res = min(res, max(d1[i][j][x], d2[i][j][x]));
    if (res == oo || move1 == 0 || move2 == 0) printf("-1");
    else printf("%d\n", res);
    return 0;
}
/** Happy Coding :D */
