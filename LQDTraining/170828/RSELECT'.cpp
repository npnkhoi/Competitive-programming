using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e3 + 5;
int n, a[N][N], res;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool sign[N][N][5][5], vis[N][N];
set<int> data[N][N];
bool inside(const int &x, const int &y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}
bool avai(const set<int> &data, const int &val) {
    return data.find(val) != data.end();
}
int main() {
    freopen("rselect.inp","r",stdin);
    //freopen("rselect.out","w",stdout);
    int dem = 0;
    scanf("%d", &n);
    FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &a[i][j]);
    FOR(i, 1, n) FOR(j, 1, n)
    if (data[i][j].size() < 4) REP(k, 4) {
        int u = i + dx[k];
        int v = j + dy[k];
        int d = abs(a[i][j] - a[u][v]);
        if (!inside(u, v) || avai(data[i][j], d) || avai(data[u][v], d)) continue;
        //===================
        int cnt = 0;
        queue<ii> q; q.push(mp(i, j));
        //cout << i << " " << j << endl;
        while (!q.empty()) {
            ii t = q.front(); q.pop(); cnt ++;
            if (data[t.fi][t.se].size() == 4) continue;
            REP(z, 4) {
                u = t.fi + dx[z];
                v = t.se + dy[z];
                if (!inside(u, v) || abs(a[t.fi][t.se] - a[u][v]) != d || avai(data[u][v], d))
                continue;
                data[t.fi][t.se].insert(d);
                data[u][v].insert(d);
                q.push(mp(u, v));
                //cout << u << " " << v << endl;
                dem ++;
            }
        }
        res = max(res, cnt);
        //cout << endl;
    }
    printf("%d\n", res);
    cout << dem << endl;
    return 0;
}
/** Happy Coding ^^ */
