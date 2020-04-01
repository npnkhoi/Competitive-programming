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
#define task "SALARY"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 5e5 + 5;
int n, m, idx;
vi adj[N];
int a[N], num[N], tail[N], seq[N];
ll ft[N];
void dfs(int u) {
	//cerr << "dfs " << u << "\n";
	num[u] = tail[u] = ++ idx;
	seq[idx] = u;
	REP(j, adj[u].size()) {
		int v = adj[u][j];
		if (num[v] == 0) {
			dfs(v);
			tail[u] = tail[v];
		}
	}
}
void update(int pos, ll val) {
	for (; pos <= n; pos += pos & -pos) ft[pos] += val;
}
ll get(int pos) {
	ll res = 0;
	for (; pos; pos -= pos & -pos) res += ft[pos];
	return res;
}
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);	
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) {
		//cin >> a[i];
		scanf("%d", &a[i]);
		if (i > 1) {
			int boss; 
			//cin >> boss;
			scanf("%d", &boss);
			adj[boss].pb(i);
			//cerr << boss << " -> " << i << '\n';
		}
	}
	dfs(1);
	FOR(i, 1, n) update(i, a[seq[i]] - a[seq[i-1]]);
	//FOR(i, 1, n) cerr << num[i] << " " << tail[i] << " " << seq[i] << '\n';
	REP(khue, m) {
		char request;
		//cin >> request;
		scanf(" %c", &request);
		if (request == 'p') {
			int u;
			ll x;
			//cin >> u >> x;
			scanf("%d%lld", &u, &x);
			update(num[u] + 1, x);
			update(tail[u] + 1, -x);
			//FOR(i, 1, n) cerr << get(i) << " "; cerr << "\n"; 
		} else {
			int u;
			//cin >> u;
			scanf("%d", &u);
			cout << get(num[u]) << '\n';
		}
	}
}
