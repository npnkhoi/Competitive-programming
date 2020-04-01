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
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

void dfs(int u, int par) {
	wei[u] = 1;
	REP(j, adj[u].size()) {
		int v = adj[u][j].fi;
		if (v != par) {
			dfs(v);
			wei[u] += wei[v];
			dad[v] = u;
		}
	}
}
void hld(int u, int par, int edge) {	
	num[u] = idx ++;
	a[idx] = edge;
	int w = -1;
	REP(j, adj[u].size()) {
		int v = adj[u][j];
		if (v != par && (w == -1 || wei[v] > wei[w])) w = v;
	}

	if (w != -1) {
		head[w] = head[]
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> q;
	FOR(i, 1, n-1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(mp(u, c));
		adj[v].pb(mp(v, c));
		e[i] = mp(u, v);
	}
	dfs(1, -1);
	head[1] = 1;
	hld(1, -1, 0);

	REP(khue, tc) {
		int u, v;
		cin >> type >> x >> y;
		if (type == 1) {
			int u = e[x].fi, v = e[x].se;
			if (u == dad[v]) swap(u, v);
			update(1, num[u], a[num[u]] ^ y);
			a[num[u]] = y;
		} else {
			int t = lca(u, v);
			cout << getPath(u, t) ^ getPath(v, t) << "\n";
		}
	}
}
