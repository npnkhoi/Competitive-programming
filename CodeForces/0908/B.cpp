#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 55;
const int L = 105;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int m, n, p[4];
char a[N][N], s[L];
ii start;
bool inside(int x, int y) {
    return 1 <= x && x <= m && 1 <= y && y <= n;
}

bool check() {
    int x = start.fi, y = start.se;
    REP(i, strlen(s)) {
        int dir = p[s[i] - '0'];
        x += dx[dir]; y += dy[dir];
        if (!inside(x, y)) return 0;
        if (a[x][y] == '#') return 0;
        if (a[x][y] == 'E') return 1;
    }
    return 0;
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) {
        scanf(" %c", &a[i][j]);
        if (a[i][j] == 'S') start = mp(i, j);
    }
    scanf("%s", &s);
    int res = 0;
    REP(i, 4) p[i] = i;
    do {
        res += check();
    } while (next_permutation(p, p+4));
    printf("%d", res);
}
/// Expelliarmus !
