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
#define task "PATHS"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e4 + 5;

int n, m;
vi adj[N];
int vis[N];
bool res;
void dfs(int u, int par) {
	REP(j, adj[u].size()) {
		int v = adj[u][j];
		if (vis[v] == 0) {
			vis[v] = - vis[u];
			dfs(v, u);
		} else {
			if (vis[v] == vis[u]) res = 1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	int tc; cin >> tc;
	REP(khue, tc) {
		cin >> n >> m;
		FOR(i, 1, n) adj[i].clear();
		REP(i, m) {
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		memset(vis, 0, sizeof vis);
		res = 0;
		FOR(i, 1, n) if (vis[i] == 0) {
			vis[i] = 1;
			dfs(i, -1);
			if (res) break;
		}
		cout << (res ? "YES\n" : "NO\n");
	}
}
