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
#define task "PERFECT"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
int n, k, s;

vi adj[N];
int degIn[N], num[N], tail[N], idx, ft[N], a[N];
ll res;

void dfs(int u) {
	num[u] = tail[u] = ++ idx;
	a[idx] = u;
	REP(j, adj[u].size()) {
		int v = adj[u][j];
		dfs(v);
		tail[u] = tail[v];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> n >> k;
	REP(i, n-1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		degIn[v] ++;
	}		
	FOR(i, 1, n) if (degIn[i] == 0) s = i;
	dfs(s);
	FOR(u, 1, n) {
		FOR(i, num[u] + 1, tail[u]) {
			if (abs(a[i] - u) <= k) res ++;
		}
	}
	cout << res;
}
