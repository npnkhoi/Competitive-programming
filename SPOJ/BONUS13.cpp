#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define taskName "0"
const int N = 10;
const int K = 70;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
struct pack {
    int x, y, p;
};

pack v[K];
vector<ii> Free;
int vis[N][N], p[N][N];
ll points, res;
int cnt, n;

void update(int x, int y) {
    if (vis[x][y] != cnt) {
        vis[x][y] = cnt;
        points += p[x][y];
    }
}
int main() {
    freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d", &n);
    REP(i, n) {
        int x, y, val;
        scanf("%d%d%d", &x, &y, &val);
        p[x][y] = val;
    }
    FOR(i, 1, 8) FOR(j, 1, 8) if (p[i][j] == 0) Free.pb(mp(i, j));

    REP(a, 64 - n)
    REP(b, 64 - n) if (b != a)
    REP(c, 64 - n) if (c != b && c != a)
    REP(d, 64 - n) if (d != c && d != b && d != a) {
        points = 0;
        ++ cnt;

        //memset(vis, 0, sizeof vis);
        int x, y;

        // Queen
        x = Free[a].fi, y = Free[a].se;
        FOR(j, 1, 8) update(x, j);
        FOR(i, 1, 8) update(i, y);
        FOR(i, 1, 8) {
            int j = i + y - x;
            if (1 <= j && j <= 8) update(i, j);
            j = y + x - i;
            if (1 <= j && j <= 8) update(i, j);
        }

        // Rook
        x = Free[b].fi, y = Free[b].se;
        FOR(j, 1, 8) update(x, j);
        FOR(i, 1, 8) update(i, y);

        // Bishop
        x = Free[c].fi, y = Free[c].se;
        FOR(i, 1, 8) {
            int j = i + y - x;
            if (1 <= j && j <= 8) update(i, j);
            j = y + x - i;
            if (1 <= j && j <= 8) update(i, j);
        }

        // Knight
        x = Free[d].fi, y = Free[d].se;
        REP(z, 8) {
            int u = x + dx[z];
            int v = y + dy[z];
            if (1 <= u && u <= 8 && 1 <= v && v <= 8) update(u, v);
        }

        res = max(res, points);
    }
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding :D */
