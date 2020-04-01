#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <cstdlib>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "labyr"
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1005;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
char a[N][N];
ii start, par[N][N];
queue<ii> q;
int m, n;
void trace(int u, int v) {
    if (mp(u, v) != start) trace(par[u][v].fi, par[u][v].se);
    printf("%d %d\n", u, v);
}
bool inside(int x, int y) {
    return 1 <= x && x <= m && 1 <= y && y <= n;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) {
        scanf(" %c", &a[i][j]);
        if (a[i][j] == 'E') start = mp(i, j);
    }
    a[start.fi][start.se] = 'X';
    q.push(start);

    int res = 0;
    while (!q.empty()) {
        res ++;
        int siz = q.size();
        while (siz --) {
            int x = q.front().fi;
            int y = q.front().se;
            q.pop();
            REP(z, 4) {
                int u = x + dx[z], v = y + dy[z];
                if (!inside(u, v)) {
                    printf("%d\n", res);
                    trace(x, y);
                    exit(0);
                } else if (a[u][v] == 'O') {
                    //cerr << u << " " << v << "\n";
                    q.push(mp(u, v));
                    par[u][v] = mp(x, y);
                    a[u][v] = 'X';
                }
            }
        }
    }
    printf("-1");

}
/// Expelliarmus !
