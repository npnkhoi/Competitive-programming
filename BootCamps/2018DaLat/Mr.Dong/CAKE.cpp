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
#define FORD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 405;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int x[N], y[N], u[N], v[N];
int id[(int)1e6+5];
bool vis[N][N];
int m, n, k;

void cover(int x, int y, int u, int v) {
    FOR(i, x, u) FOR(j, y, v) vis[i][j] = 1;
}
bool inside(int x, int y) {
    return x >= 0 && x <= 2*id[m] && y >= 0 && y <= 2*id[n];
}
void flood(int i, int j) {
    //printf("flood %d %d\n", i, j);
    vis[i][j] = 1;
    queue<ii> q; q.push(mp(i, j));
    while (!q.empty()) {
        ii tmp = q.front(); q.pop();
        REP(z, 4)  {
            int u = tmp.fi + dx[z];
            int v = tmp.se + dy[z];
            if (inside(u, v) && vis[u][v] == 0) {
                vis[u][v] = 1;
                q.push(mp(u, v));
                //cout << u << " " << v << endl;
            }
        }
    }
}

int main() {
    freopen("CAKE.inp", "r", stdin);
    freopen("CAKE.out", "w", stdout);
    while (scanf("%d%d", &m, &n) != EOF) {
        if (m == 0 && n == 0) break;
        swap(m, n);
        scanf("%d", &k);
        vector<int> data;
        //cout << k << endl;
        FOR(i, 1, k) {
            scanf("%d%d%d%d", &x[i], &y[i], &u[i], &v[i]);
            if (x[i] > u[i]) swap(x[i], u[i]);
            if (y[i] > v[i]) swap(y[i], v[i]);
            //cerr << x[i] << y[i];
            data.push_back(x[i]);
            data.push_back(y[i]);
            data.push_back(u[i]);
            data.push_back(v[i]);
        }
        data.push_back(0);
        data.push_back(m);
        data.push_back(n);

        sort(data.begin(), data.end());
        int p = -1;
        REP(i, data.size())
        if (i == 0 || data[i] != data[i-1]) id[data[i]] = ++p;
        //FOR(i, 1, k) printf("%d %d %d %d\n", 2*id[x[i]], 2*id[y[i]], 2*id[u[i]], 2*id[v[i]]);

        memset(vis, 0, sizeof vis);
        FOR(i, 1, k) {
            //printf("%d %d %d %d\n", 2*id[x[i]], 2*id[y[i]], 2*id[u[i]], 2*id[v[i]]);
            cover(2*id[x[i]], 2*id[y[i]], 2*id[u[i]], 2*id[y[i]]);
            cover(2*id[x[i]], 2*id[v[i]], 2*id[u[i]], 2*id[v[i]]);
            cover(2*id[x[i]], 2*id[y[i]], 2*id[x[i]], 2*id[v[i]]);
            cover(2*id[u[i]], 2*id[y[i]], 2*id[u[i]], 2*id[v[i]]);
        }
        /*FOR(i, 0, 2*id[m]) {
            FOR(j, 0, 2*id[n]) cout << vis[i][j] << " ";
            cout << "\n";
        }*/
        int cnt = 0;
        //cout << id[m] << " " << id[n] << endl;
        FOR(i, 0, 2*id[m]) FOR(j, 0, 2*id[n]) if (vis[i][j] == 0) {
            ++ cnt;
            flood(i, j);
            /*FOR(i, 0, 2*id[m]) {
                FOR(j, 0, 2*id[n]) cout << vis[i][j] << " ";
                cout << "\n";
            }*/
        }
        printf("%d\n", cnt);
    }
    return 0;
}
/** Happy Coding ^^ */

