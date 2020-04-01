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

#define task "EXPERIENCE"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

int n, w[N];
long long f[N], sumChild[N];
vi adj[N];

void calc(int root, int minW, int maxW, long long sum, int u, int par) {
	f[root] = max(f[root], maxW - minW + sum);

	REP(i, adj[u].size()) {
		int v = adj[u][i];
		if (v == par) continue;
		calc(root, min(minW, w[v]), max(maxW, w[v]), sum - f[v] + sumChild[v], v, u);
	}
}

void dfs(int u, int par) {
	REP(i, adj[u].size()) {
		int v = adj[u][i];
		if (v == par) continue;
		dfs(v, u);
		sumChild[u] += f[v];
	}
	calc(u, w[u], w[u], sumChild[u], u, par);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen(task".inp", "r", stdin);
	// freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) cin >> w[i];
	REP(i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cout << f[1];
	return 0;
}
