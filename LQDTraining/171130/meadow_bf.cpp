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

#define taskName "meadow"

const int M = 1e5 + 5;
const int N = 50 + 5;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int m, n, a[M][N], mark[M][N];
vector<ii> seg[M];
int id[M][N], root[N*M], Rank[N*M];

void flood(int x, int y, int lo, int hi, int idx) {
    queue<ii> q; q.push(mp(x, y));
    mark[x][y] = idx;
    while (!q.empty()) {
        ii tmp = q.front(); q.pop();
        REP(z, 4) {
            int u = tmp.fi + dx[z];
            int v = tmp.se + dy[z];
            if (lo <= u && u <= hi && 1 <= v && v <= n && a[u][v] && mark[u][v] != idx) {
                mark[u][v] = idx;
                q.push(mp(u, v));
            }
        }
    }
}
void sub1() {
    //cerr << "sub1\n";
    int idx = 0;
    int res = 0;
    FOR(u, 1, m) {
        //cerr << "row" << u << "\n";
        FOR(v, u, m) {
            ++ idx;
            //cerr << idx << "\n";
            FOR(i, u, v) FOR(j, 1, n) if (a[i][j] && mark[i][j] != idx) {
                flood(i, j, u, v, idx);
                res ++;
            }
        }
        //cerr << "res: " << res << "\n";
    }
    printf("%d\n", res);
}
int getRoot(int u) {
    if (root[u] == -1) return u;
    else return root[u] = getRoot(root[u]);
}
void join(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    if (u != v) {
        if (Rank[u] > Rank[v]) root[v] = u;
        else {
            root[u] = v;
            Rank[v] += Rank[u] == Rank[v];
        }
    }
}
void sub2() {
    FOR(i, 1, m) {
        int tmp = 0;
        FOR(j, 1, n) if (a[i][j]) {
            if (tmp == 0) tmp = j;
        } else if (tmp != 0) {
            seg[i].push_back(mp(tmp, j-1));
            tmp = 0;
        }
    }
    //cerr << "ok\n";

    ll res = 0;
    FOR(u, 1, m) {
        int idx = 0;
        int cnt = 0;
        FOR(v, u, m) {
            //printf("%d %d\n", u, v);
            FOR(j, 1, n) if (a[v][j]) {
                if (j == 1 || a[v][j-1] == 0) {
                    ++ idx;
                    cnt ++;
                    root[idx] = -1;
                    Rank[idx] = 0;
                }
                mark[v][j] = idx;
            }

            if (v > u)
            FOR(j, 1, n) if (a[v][j] && a[v-1][j]) {
                int khoi = mark[v][j];
                int khue = mark[v-1][j];
                //printf("<- %d\n", v);
                //cerr << khoi << "  " << khue << "\n";
                if (getRoot(khoi) != getRoot(khue)) {
                    join(khoi, khue);
                    cnt --;
                }
            }
            res += cnt;
        }
    }
    printf("%lld\n", res);
}
int main() {
    freopen(taskName".inp", "r", stdin);
    freopen(taskName".ans", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) {
        char ch;
        scanf(" %c", &ch);
        a[i][j] = ch - '0';
    }
    sub1();
    return 0;
}
/** Happy Coding :D */
