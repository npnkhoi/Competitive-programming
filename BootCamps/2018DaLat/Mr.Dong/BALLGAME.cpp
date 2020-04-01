using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 105;
const ll oo = 1e15 + 7;
int n, m;
int x[N], y[N], u[N], v[N];
ll a[N][N];
bool cam[N][N], cannot[N][N], vis[N][N];
queue<ii> q;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void sub1() {
    scanf("%d", &m);
    FOR(i, 1, m) scanf("%d%d", &u[i], &v[i]);
    sort(u+1, u+m+1);
    sort(v+1, v+m+1);
    int resU = u[(m+1)/2];
    int resV = v[(m+1)/2];
    //cout << resU << " " << resV << endl;
    ll res = 0;
    FOR(i, 1, m) res += abs(resU - u[i]);
    FOR(i, 1, m) res += abs(resV - v[i]);
    printf("%lld", res);
}
bool inside(int u, int v) {
    return u >= 0 && u <= 100 && v >= 0 && v <= 100;
}
void sub2() {
    int xx, yy;
    FOR(i, 1, n) {
        scanf("%d%d", &xx, &yy);
        cam[xx][yy] = 1;
    }
    scanf("%d", &m);
    while (m--) {
        memset(vis, 0, sizeof vis);
        int z, t;
        scanf("%d%d", &z, &t);
        q.push(mp(z, t)); vis[z][t] = 1;
        int cnt = 0;
        while (!q.empty()) {
            ++ cnt;
            int si = q.size();
            while (si --) {
                ii tmp = q.front(); q.pop();
                //cout << tmp.fi << " " << tmp.se << endl;
                REP(g, 4) {
                    int uu = tmp.fi + dx[g];
                    int vv = tmp.se + dy[g];
                    if (vis[uu][vv] == 0 && cam[uu][vv] == 0 && inside(uu, vv)) {
                        a[uu][vv] += cnt;
                        vis[uu][vv] = 1;
                        q.push(mp(uu, vv));
                    }
                }
            }
        }
        FOR(i, 0, 100) FOR(j, 0, 100)
        if (cam[i][j] == 0 && vis[i][j] == 0) cannot[i][j] = 1;
    }

    ll res = oo;
    FOR(i, 0, 100) FOR(j, 0, 100)
    if (cam[i][j] == 0 && cannot[i][j] == 0) res = min(res, a[i][j]);
    if (res != oo) printf("%lld\n", res);
    else printf("-1\n");
}
int main() {
    freopen("BALLGAME.inp", "r", stdin);
    freopen("BALLGAME.out", "w", stdout);
    scanf("%d", &n);
    if (n == 0) sub1();
    else sub2();
    return 0;
}
/** Happy Coding ^^ */

