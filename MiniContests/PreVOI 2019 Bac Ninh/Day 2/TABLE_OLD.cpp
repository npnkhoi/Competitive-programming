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
int a[N][N];
int f[N][N], g[N][N], res;

void calc(int f[][N]) {
    f[u][v] = a[u][v];
    FOR(j, v + 1, q) f[u][j] = a[u][j] + f[u][j - 1];
    FOR(i, u + 1, p) f[i][v] = a[i][v] + f[i - 1][v];
    FOR(i, u + 1, p) FOR(j, v + 1, q)
        f[i][j] = a[i][j] + max(f[i - 1][j], f[i][j - 1]);
}

void trace(int x, int y) {
    //cerr << x << ' ' << y << '\n';
    if (x == u && y == v) return;
    if (mp(x, y) != mp(u, v) && mp(x, y) != mp(p, q)) {
        ll tmp = a[x][y];
        a[x][y] = -oo;
        calc(g);
        a[x][y] = tmp;
        res = min(res, g[p][q]);
    }
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
        //cerr << k << '\n';
        cin >> u >> v >> p >> q;
        calc(f);
        res = oo;
        trace(p, q);
        cout << res << '\n';
    }
}
