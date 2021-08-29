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
#define task "test"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2000 + 5;
vi child[N], adj[N];
int n, k, idx, cc;
int preOrd[N], postOrd[N], mark[N], lab[N];
void preDFS(int u) {
	preOrd[++idx] = u;
	REP(j, child[u].size()) preDFS(child[u][j]);
}
void postDFS(int u) {
	REP(j, child[u].size()) postDFS(child[u][j]);
	postOrd[++idx] = u;
}
void dfs(int u) {
	mark[u] = 1; lab[u] = cc;
	REP(j, adj[u].size()) {
		int v = adj[u][j];
		if (!mark[v]) dfs(v);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	int tc; cin >> tc;	
	FOR(iTest, 1, tc) {
		cin >> n >> k;
		FOR(i, 1, n) {
			child[i].clear();
			int u, v;
			cin >> u >> v;
			if (u) child[i].pb(u);
			if (v) child[i].pb(v);
		}
		idx = 0;
		preDFS(1);
		idx = 0;
		postDFS(1);
		//FOR(i, 1, n) cerr << preOrd[i] << " "; cerr << "\n";
		//FOR(i, 1, n) cerr << postOrd[i] << " "; cerr << "\n";

		FOR(i, 1, n) adj[i].clear();
		FOR(i, 1, n) {
			adj[preOrd[i]].pb(postOrd[i]);
			adj[postOrd[i]].pb(preOrd[i]);
		}

		cc = 0;
		memset(mark, 0, sizeof mark);
		FOR(i, 1, n) if (!mark[i]) {
			if (cc < k) cc ++;
			dfs(i);
		}
		cout << "Case #" << iTest << ": "; 
		if (cc < k) cout << "Impossible\n";
		else {
			FOR(i, 1, n) cout << lab[i] << " ";
			cout << "\n";
		}
	}
}
