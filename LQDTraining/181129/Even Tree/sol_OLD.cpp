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

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

void directTree(int u, int par) {
	REP(i, adj[u].size()) {
		int v = adj[u][i];
		if (v == par) {
			swap(adj[u][i], adj[u].back());
			adj[u].pop_back();
			i --;
			continue;
		}
		dfs(v, u);
	}
}

void dfs(int u) {
	cnt[u] = 1;
	for (int v : adj[u]) {
		dfs(v);
		cnt[u] += cnt[v];
	}
	res += (cnt[u] % 2 == 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m;
	REP(i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	directTree(1, -1);
	dfs(1);
	return 0;
}
