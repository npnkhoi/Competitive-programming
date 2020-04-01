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
#define taskName ""
const int N = 67;
struct pack {
    int x, y, p;
};
pack v[N];
vector<ii> Free;
bool mark[N][N];
ii queen, rook, bishop, knight;
int n;
bool reach(int x, int y) {
    if (x == queen.fi || y == queen.se) return 1;
    if (x - y == queen.fi - queen.se || x + y == queen.fi + queen.se) return 1;
    if (x - y == bishop.fi - bishop.se || x + y == bishop.fi + bishop.se) return 1;
    if (x == rook.fi || y == rook.se) return 1;
    int dx = abs(knight.fi - x), dy = abs(knight.se - y);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].p);
        mark[v[i].x][v[i].y] = 1;
    }
    FOR(i, 1, 8) FOR(j, 1, 8) if (!mark[i][j]) Free.pb(mp(i, j));
    ll res = 0;
    REP(i, 64 - n)
    REP(j, 64 - n) if (j != i)
    REP(k, 64 - n) if (k != i && k != j)
    REP(l, 64 - n) if (l != i && l != j && l != k) {
        ll points = 0;

        queen = Free[i];
        rook = Free[j];
        knight = Free[k];
        bishop = Free[l];

        REP(z, n)
            if (reach(v[z].x, v[z].y))
            points += v[z].p;

        res = max(res, points);
    }
    printf("%lld\n", res);
    return 0;
}
/** Happy Coding :D */
