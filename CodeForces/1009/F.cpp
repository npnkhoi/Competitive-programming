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

const int N = 1e6 + 5;
int n, idx;
vi adj[N], layer[N];
int num[N], tail[N], dep[N];
void dfs(int u, int par, int depth) {
	num[u] = tail[u] = ++ idx;
	dep[u] = depth;
	layer[depth].pb(num[u]);
	//cerr << num[u] << " " << depth << "\n";
	REP(j, adj[u].size()) {
		int v = adj[u][j];
		if (v != par) {
			dfs(v, u, depth + 1);
			tail[u] = tail[v];
		}
	}
} 
int calc(int u, int l, int r) {
	return upper_bound(layer[u].begin(), layer[u].end(), r) - upper_bound(layer[u].begin(), layer[u].end(), l - 1);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	REP(i, n-1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, -1, 0);
	FOR(u, 1, n) {
		if (num[u] == tail[u]) {
			cout << "0\n";
		} else {
			int l = dep[u], r = n-1, bs = r;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (calc(mid, num[u], tail[u]) >= calc(mid + 1, num[u], tail[u])) {
					bs = mid;
					r = mid - 1;
				} else l = mid + 1;
			}
			cout << bs - dep[u] << "\n";
		}
	}
}
