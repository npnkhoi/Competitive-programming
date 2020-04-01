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
int a[N][N];
bool sign[N][N];
int m, n, p, res;
int cnt[N];
queue<ii> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool ok(int x, int y) {
    return sign[x][y] == 0 &&
    x >= 1 && x <= m && y >= 1 && y <= n;
}
int main() {
    freopen("SQNET.inp", "r", stdin);
    freopen("SQNET.out", "w", stdout);
    scanf("%d%d%d", &m, &n, &p);
    int x, y, u, v;
    for (int i = 1; i <= p; ++i){
        scanf("%d%d%d%d", &x, &y, &u, &v);
        for (int i = x; i <= u; ++i)
        for (int j = y; j <= v; ++j) ++ a[i][j];
    }
    /*for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) printf("%5d", a[i][j]);
        cout << endl;
    }*/
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) if (a[i][j] != 0 && sign[i][j] == 0) {
        cnt[a[i][j]] ++;
        sign[i][j] = 1; q.push(mp(i, j));
        //cout << "\n" << i << " " << j << endl;
        while (!q.empty()) {
            ii tmp = q.front(); q.pop();
            for (int z = 0; z < 4; z++) {
                int xx = tmp.fi + dx[z];
                int yy = tmp.se + dy[z];
                if (ok(xx, yy) && a[xx][yy] == a[i][j]) {
                    sign[xx][yy] = 1;
                    q.push(mp(xx, yy));
                    //cout << xx << " " << yy << endl;
                }
            }
        }
    }
    for (int i = 1; i <= p; i++) printf("%d\n", cnt[i]);
    return 0;
}
/** Happy Coding ^^ */


