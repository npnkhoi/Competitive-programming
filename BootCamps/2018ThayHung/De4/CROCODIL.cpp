#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
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

char inf(ii t) {
    return a[t.fi][t.se];
}

bool findTarget() {
    FOR(i, 1, m) if (!row[i].empty()) {
        if (inf(row[i].front()) == 'W') {
            x = row[i].front().fi;
            y = row[i].front().se;
            return 1;
        }
        if (inf(row[i].back()) == 'E') {
            x = row[i].back().fi;
            y = row[i].back().se;
            return 1;
        }
    }
    FOR(i, 1, n) if (!col[i].empty()) {
        if (inf(col[i].front()) == 'N') {
            x = col[i].front().fi;
            y = col[i].front().se;
            return 1;
        }
        if (inf(col[i].back()) == 'S') {
            x = col[i].back().fi;
            y = col[i].back().se;
            return 1;
        }
    }
    return 0;
}
void update() {
    //cerr << x << " " << y << "\n";
    a[x][y] = '.';
    res ++;
    FOR(i, 1, m) {
        while (!row[i].empty() && inf(row[i].front()) == '.') row[i].pop_front();
        while (!row[i].empty() && inf(row[i].back()) == '.') row[i].pop_back();
    }
    FOR(i, 1, n) {
        while (!col[i].empty() && inf(col[i].front()) == '.') col[i].pop_front();
        while (!col[i].empty() && inf(col[i].back()) == '.') col[i].pop_back();
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) {
        scanf(" %c", &a[i][j]);
        if (a[i][j] != '.') {
            row[i].pb(mp(i, j));
            col[j].pb(mp(i, j));
        }
    }
    while (findTarget()) update();
    printf("%d\n", res);
}
