#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "TABLE"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 305;
const int oo = 1e9 + 7;

int m, n, k, u, v, p, q;
int a[N][N], f[N][N], g[N][N], row[2 * N], lay[2 * N], res;

void trace(int x, int y) {
    row[x + y] = x;
    if (x == u && y == v) return;
    if (f[x-1][y] + a[x][y] == f[x][y]) trace(x-1, y);
    else trace(x, y-1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> m >> n >> k;
    FOR(i, 1, m) {
        FOR(j, 1, n) cin >> a[i][j];
    }
    while (k--) {
        cin >> u >> v >> p >> q;

        f[u][v] = a[u][v];
        FOR(j, v + 1, q) f[u][j] = a[u][j] + f[u][j - 1];
        FOR(i, u + 1, p) f[i][v] = a[i][v] + f[i - 1][v];
        FOR(i, u + 1, p) FOR(j, v + 1, q)
            f[i][j] = a[i][j] + max(f[i - 1][j], f[i][j - 1]);

        trace(p, q);

        g[p][q] = a[p][q];
        FORD(j, q - 1, v) g[p][j] = a[p][j] + g[p][j + 1];
        FORD(i, p - 1, u) g[i][q] = a[i][q] + g[i + 1][q];
        FORD(i, p - 1, u) FORD(j, q - 1, v)
            g[i][j] = a[i][j] + max(g[i + 1][j], g[i][j + 1]);

        FOR(i, u + v, p + q) lay[i] = -oo;
        FOR(i, u, p) FOR(j, v, q) {
            if (i == row[i + j]) continue;
            lay[i + j] = max(lay[i + j], f[i][j] + g[i][j] - a[i][j]);
        }
        res = oo;
        FOR(i, u + v + 1, p + q - 1) res = min(res, lay[i]);
        cout << res << '\n';
    }
}
