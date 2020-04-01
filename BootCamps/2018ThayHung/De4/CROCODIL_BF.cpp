#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)
#define task "crocodil"

const int N = 2005;
deque<ii> row[N], col[N];
char a[N][N];
int m, n, res, x, y;

bool ok(int x, int y) {
    //cerr << a[x][y] << (a[x][y] == 'E') << "\n";
    if (a[x][y] == 'N') {
        FOR(i, 1, x-1) if (a[i][y] != '.') return 0;
    }
    else if (a[x][y] == 'S') {
        FOR(i, x+1, m) if (a[i][y] != '.') return 0;
    }
    else if (a[x][y] == 'E') {
        FOR(j, y+1, n) if (a[x][j] != '.') return 0;
    }
    else if (a[x][y] == 'W') {
        FOR(j, 1, y-1) if (a[x][j] != '.') return 0;
    }
    return 1;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) scanf(" %c", &a[i][j]);
    int res = 0;
    while (1) {
        bool cont = 1;
        bool sol = 0;
        for (int i = 1; i <= m && cont; i++)
        for (int j = 1; j <= n && cont; j++)
        if (a[i][j] != '.' && ok(i, j)) {
            a[i][j] = '.';
            //cout << i << " " << j << "\n";
            cont = 0;
            sol = 1;
        }
        if (!sol) break; else res ++;
    }
    printf("%d", res);
}
