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

const int N = 1e5 + 5;
int n, q, m;
int lab[N];
vector<ii> adj[N];
map<int, int> wei[N];
vi val;
vector<ll> sum;
map<int, ll> cnt;
map<int, ll> :: iterator it;

int root(int u) {
	if (lab[u] < 0) return u;
	else return lab[u] = root(lab[u]);
}

void merge(int u, int v) {
	u = root(u), v = root(v);
	if (u == v) return;
	if (lab[v] < lab[u]) swap(u, v);
	lab[u] -= (lab[u] == lab[v]);
	lab[v] = u;
	for (it = v.begin(); )
}

void dfs(int u, int par) {
	for (ii v : adj[u]) {
		if (v.fi == par) continue;
		dfs(v.fi, u);
		wei[root(u)][v.se] ++;
		cnt[v.se] ++;
		int tmp = 0;
		while (!wei[root(v.fi)].empty() && wei[root(v.fi)].rbegin() -> first < v.se) {
			tmp += wei[root(v.fi)].rbegin() -> second;
			wei[root(v.fi)].erase(wei[root(v.fi)].rbegin() -> first);
		}
		if (tmp > 0) {
			wei[root(v.fi)][v.se] += tmp; 
			cnt[v.se] += tmp;
		}
		merge(u, v.fi);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);	
	cin >> n >> q;
	REP(i, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(mp(v, w));
		adj[v].push_back(mp(u, w));
	}
	memset(lab, -1, sizeof lab);
	dfs(1, -1);
	val.push_back(0); sum.push_back(0);
	for (it = cnt.begin(); it != cnt.end(); ++ it) {
		val.push_back(it -> fi);
		sum.push_back(it -> se + sum.back()); 
	}
	REP(i, q) {
		int l, r;
		cin >> l >> r;
		cout << sum[lower_bound(all(val), r) - val.begin()] - 
		sum[lower_bound(all(val), l - 1) - val.begin()] << "\n";
	}
	return 0;
}
