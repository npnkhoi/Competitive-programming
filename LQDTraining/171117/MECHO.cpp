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
const int N = 2005;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
int d[N][N], g[N][N];
char a[N][N];
bool sign[N][N];

int n, s;
ii bear;
bool inside(int i, int j) {
    return i > 0 && j > 0 && i <= n && j <= n;
}
bool ok(int x) {
    int timer = x;
    if (x >= d[bear.fi][bear.se]) {
        return 0;
    }
    queue<ii> q; q.push(bear);
    memset(sign, 0, sizeof sign);
    sign[bear.fi][bear.se] = 1;
    memset(g, -1, sizeof g);
    g[bear.fi][bear.se] = x;

    while (!q.empty()) {
        ++ timer ;
        int size = q.size();
        while (size -- ) {
            ii tmp = q.front(); q.pop();
            REP(z, 4) {
                int u = tmp.fi + di[z];
                int v = tmp.se + dj[z];
                if (a[u][v] == 'D') return 1;

                if (inside(u, v) && sign[u][v] == 0 && a[u][v] != 'T' && timer < d[u][v]) {
                    //printf("time: %d -> %d %d\n", timer, u, v);
                    q.push(mp(u, v));
                    sign[u][v] = 1;
                    g[u][v] = timer;
                }
            }
        }
    }
    return 0;
}
int main() {
    queue<ii> q;

    freopen("MECHO.inp", "r", stdin);
    freopen("MECHO.out", "w", stdout);

    memset(d, -1, sizeof d);
    scanf("%d%d", &n, &s);
    FOR(i, 1, n) FOR(j, 1, n) {
        scanf(" %c", &a[i][j]);
        if (a[i][j] == 'H') {
            q.push(mp(i, j));
            d[i][j] = 0;
        }
        else if (a[i][j] == 'M') bear = mp(i, j);
    }

    while (!q.empty()) {
        ii t = q.front(); q.pop();
        REP(z, 4) {
            int u = t.fi + di[z];
            int v = t.se + dj[z];
            if (a[u][v] != 'D' && a[u][v] != 'T' && inside(u, v) && d[u][v] == -1) {
                d[u][v] = d[t.fi][t.se] + s;
                q.push(mp(u, v));
            }
        }
    }
    FOR(i, 1, n) {
        FOR(j, 1, n) printf("%5d", d[i][j]);
        printf("\n");
    }
    printf("---\n\n\n\n\n\n");

    /*int l = 0, r = 2*n;
    int res = l;
    while (l <= r) {
        int mi = (l+r)/2;
        if (ok(s*mi)) {
            res = max(res, mi);
            l = mi + 1;
        } else r = mi - 1;
    }
    if (ok(res*s)) printf("%d\n", res);
    else printf("-1\n");*/
    cerr << ok(4*s) << "\n";
    FOR(i ,1, n) {
        FOR(j, 1, n) printf("%5d", g[i][j]);
        printf("\n");
    }
    return 0;
}
/** Happy Coding :D */

