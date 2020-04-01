#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task "0"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
vi adj[N];
int a[N], n, q;
bool ok, mark[N];
ii speed[N];

ii calc(ii v, int x, int y) {
	v.fi *= -x;
	v.se *= y;
	ll tmp = __gcd(abs(v.fi), abs(v.se));
	v.fi /= tmp;
	v.se /= tmp;
	return v;
}
void dfs(int u) {
	mark[u] = 1;
	REP(j, adj[u].size()) {
		int v = adj[u][j];
		if (!mark[v]) {
			speed[v] = calc(speed[u], a[u], a[v]);
			dfs(v);
		} else {
			ii tmp = calc(speed[u], a[u], a[v]);
			if (speed[v] != tmp) ok = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> q;
	FOR(i, 1, n) cin >> a[i];
	REP(khue, q) {
		int type; cin >> type;
		if (type == 1) {
			int x, c;
			cin >> x >> c;
			a[x] = c;
		} else if (type == 2) {
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		} else {
			int x, y, v;
			cin >> x >> y >> v;
			memset(mark, 0, sizeof mark);
			speed[x] = mp(v, 1);
			ok = 1;
			dfs(x);
			if (!mark[y] || !ok) cout << "0\n";
			else cout << speed[y].fi << "/" << speed[y].se << "\n";
		}
	}
}
