#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "lexlcs"

const int N = 4e3 + 5;
char a[N], b[N];
//ii f[N][N],  g[N][N];
int f[N][N], g[N][N];
vector<pair<int, ii> > save1[N], save2[N];
int m, n;

/*void trace1(int i, int j) {
    if (f[i][j].fi == 0) return;
    if (a[i] == b[j] && f[i][j] == mp(f[i-1][j-1].fi + 1, a[i] - 'a')) {
        printf("%c", a[i]);
        trace1(i-1, j-1);
    } else if (f[i-1][j] == f[i][j]) {
        trace1(i-1, j);save2[i][j].fi.fi
    } else {
        trace1(i, j-1);
    }
}
void solve1() {
    FOR(i, 1, m) FOR(j, 1, n) {
        f[i][j] = max(f[i][j-1], f[i-1][j]);
        if (a[i] == b[j]) {
            f[i][j] = max(f[i][j], mp(f[i-1][j-1].fi + 1, a[i] - 'a'));
        }
    }
    trace1(m, n);
}
void trace2(int i, int j) {
    if (g[i][j].fi == 0) return;
    if (a[i] == b[j] && g[i][j] == mp(g[i-1][j-1].fi + 1, a[i] - 'a')) {
        printf("%c", a[i]);
        trace2(i-1, j-1);
    } else if (g[i][j] == mp(g[i-1][j].fi + 1, a[i] - 'a')) {
        printf("%c", a[i]);
        trace2(i-1, j);
    } else {
        printf("%c", b[j]);
        trace2(i, j-1);
    }
}
void solve2() {
    FOR(i, 1, m) g[i][0] = mp(i, a[i] - 'a');
    FOR(j, 1, n) g[0][j] = mp(j, b[j] - 'a');
    FOR(i, 1, m) FOR(j, 1, n) {
        g[i][j] = min(mp(g[i-1][j].fi + 1, a[i] - 'a'), mp(g[i][j-1].fi + 1, b[j] - 'a'));
        if (a[i] == b[j]) g[i][j] = min(g[i][j], mp(g[i-1][j-1].fi + 1, a[i] - 'a'));
    }
    trace2(m, n);
}*/
void solve1() {
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
        f[i][j] = max(f[i-1][j], f[i][j-1]);
        if (a[i] == b[j] && f[i][j] <= f[i-1][j-1] + 1) {
            f[i][j] = f[i-1][j-1] + 1;
            save1[f[i][j]].pb(mp(a[i], mp(i, j)));
        }
    }
    int x = m+1, y = n+1;
    for (int i = f[m][n]; i >= 1; i--) {
        sort(save1[i].rbegin(), save1[i].rend());
        for (int j = 0; j < save1[i].size(); ++j) {
             int u = save1[i][j].se.fi, v = save1[i][j].se.se, c = save1[i][j].fi;
             if (u < x && v < y) {
                x = u, y = v;
                printf("%c", c);
                break;
             }
        }
    }
}
void solve2() {
    for (int i = 1; i <= m; i++) {
        f[i][0] = i;
        save2[i].push_back(mp(a[i], mp(i, 0)));
    }

    for (int i = 1; i <= n; i++) {
        f[0][i] = i;
        save2[i].push_back(mp(b[i], mp(0, i)));
    }

    for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
        f[i][j] = min(f[i-1][j], f[i][j-1]) + 1;
        if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i-1][j-1] + 1);

        if (f[i][j] == f[i-1][j] + 1) save2[f[i][j]].push_back(mp(a[i], mp(i, j)));
        if (f[i][j] == f[i][j-1] + 1) save2[f[i][j]].push_back(mp(b[j], mp(i, j)));
        if (a[i] == b[j] && f[i][j] == f[i-1][j-1] + 1)
            save2[f[i][j]].push_back(mp(a[i], mp(i, j)));
    }
    for (int i = 1; i <= f[m][n]; i++) {
        cerr << i << ": ";
        for (int j = 0; j < save2[i].size(); j++)
            cerr << (char)save2[i][j].fi << " " << save2[i][j].se.fi << " "  << save2[i][j].se.se << "\n";
    }
    cerr << f[m][n] << "\n";
    int x = m+1, y = n+1;
    for (int i = f[m][n]; i >= 1; --i) {
        sort(save2[i].begin(), save2[i].end());
        for (int j = 0; j < save2[i].size(); ++j) {
            int u = save2[i][j].se.fi, v = save2[i][j].se.se, c = save2[i][j].fi;
            if ((u == x && v == y - 1) || (u == x - 1 && y == v) ||
            (u == x-1 && v == y-1 && a[x] == b[y])) {
                x = u, y = v;
                printf("%c %d %d\n", c, x, y);
                break;
            }
        }
    }
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%s", a+1);
    scanf("%s", b+1);
    //cerr << a+1 << " " << b+1 << "\n";
    m = strlen(a+1), n = strlen(b+1);
    reverse(a+1, a+m+1);
    reverse(b+1, b+n+1);
    solve1();
    printf("\n");
    solve2();
}
/** Happy Coding :D */
