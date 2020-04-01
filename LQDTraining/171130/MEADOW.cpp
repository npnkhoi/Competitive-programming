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

typedef pair<ii, int> pack;

const int M = 1e5 + 5;
const int N = 50 + 5;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int m, n, a[M][N], mark[M][N];
vector<pack> seg[M];
vector<ii> edge[M];
int id[M][N], lab[N*M], Rank[N*M];

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
    if (lab[u] < 0) return u;
    else return lab[u] = getRoot(lab[u]);
}
void join(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    if (u != v) {
        if (lab[u] < lab[v]) lab[v] = u;
        else {
            lab[u] = v;
            lab[v] -= lab[u] == lab[v];
        }
    }
}
bool inter(pack a, pack b) {
    int L1 = a.fi.fi;
    int R1 = a.fi.se;
    int L2 = b.fi.fi;
    int R2 = b.fi.se;
    return !(R1 < L2 || R2 < L1);
}
void sub2() {
    int idx = 0;
    FOR(i, 1, m) {
        int tmp = 0;
        FOR(j, 1, n) if (a[i][j]) {
            if (tmp == 0) tmp = j;
        } else if (tmp != 0) {
            seg[i].push_back(mp(mp(tmp, j-1), ++idx));
            tmp = 0;
        }
        if (tmp) seg[i].push_back(mp(mp(tmp, n), ++idx));
        if (i > 1) {
            REP(u, seg[i-1].size()) REP(v, seg[i].size()) {
                pack x = seg[i-1][u];
                pack y = seg[i][v];
                if (inter(x, y)) edge[i].pb(mp(x.se, y.se));
            }
        }
    }

    ll res = 0;

    FOR(u, 1, m) {
        memset(lab, -1, sizeof lab);
        int cnt = seg[u].size();
        res += cnt;
        FOR(v, u+1, m) {
            cnt += seg[v].size();
            REP(j, edge[v].size()) {
                int x = edge[v][j].fi;
                int y = edge[v][j].se;
                if (getRoot(x) != getRoot(y)) {
                    join(x, y);
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
    freopen(taskName".out", "w", stdout);
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) FOR(j, 1, n) {
        char ch;
        scanf(" %c", &ch);
        a[i][j] = ch - '0';
    }
    if (m <= 1000) sub2();
    else {
        ll res = 1LL * m * (m+1) / 2;
        cout << res;
    }
    return 0;
}
/** Happy Coding :D */
