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

#define task "COLPATHS"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 3e5 + 5, PER = 125, K = 7, MASK = 34;

int n, m, k, col[N], mark[K], idx;
ll f[MASK][N], res;
map<vi, int> id;
vi vec[PER], adj[N], v;

void input() {
	cin >> n >> m >> k;
	FOR(i, 1, n) {
		cin >> col[i];
	}
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

bool getBit(int x, int i) {
    return x & (1 << i);
}

void solve() {
    long long res = 0;
    REP(mask, (1 << k)) {
        FOR(u, 1, n) {
            if (getBit(mask, col[u] - 1) == 0) continue;
            if (__builtin_popcount(mask) == 1) {
                f[mask][u] = 1;
                //res ++;
                continue;
            }
            REP(j, adj[u].size()) {
                int v = adj[u][j];
                if (col[v] == col[u] ||
                    getBit(mask, col[v] - 1) == 0) continue;
                f[mask][u] += f[mask ^ (1 << col[u] - 1)][v];
            }
            res += f[mask][u];
            //cerr << mask << ' ' << u << ' ' << f[mask][u] << '\n';
        }
    }
    cout << res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
	input();
	solve();
}
