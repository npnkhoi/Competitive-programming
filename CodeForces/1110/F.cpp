#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()
#define task ""
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

const int N = 5e5 + 5;
const lint oo = 1e18 + 7;

struct STNode {
	int l, r;
	lint val, lazy;
};

struct LazySegmentTree {
	vector<STNode> a;
	void build(lint s[], int p, int l, int r) {
		a[p].l = l;
		a[p].r = r;
		if (l < r) {
			int mid = (l + r) / 2;
			build(s, 2 * p, l, mid);
			build(s, 2 * p + 1, mid + 1, r);
			a[p].val = min(a[2 * p].val, a[2 * p + 1].val);
		} else {
			a[p].val = s[l];
		}
	}
	void init(lint s[], int n) {
		a.resize(8 * n + 1);
		build(s, 1, 1, n);
	}
	void down(int p) {
		a[2 * p].lazy += a[p].lazy;
		a[2 * p + 1].lazy += a[p].lazy;
		// depend on type of query
		a[p].val += a[p].lazy;
		a[p].lazy = 0;
	}
	void update(int p, int l, int r, int val) {
		down(p);
		if (a[p].l > r || l > a[p].r) return;
		if (l <= a[p].l && a[p].r <= r) {
			a[p].lazy = val;
			down(p);
			return;
		}
		update(2 * p, l, r, val);
		update(2 * p + 1, l, r, val);
		// depend on type of query
		a[p].val = min(a[2 * p].val, a[2 * p + 1].val);
	}
	lint get(int p, int l, int r) {
		down(p);
		if (a[p].l > r || l > a[p].r) return oo;
		if (l <= a[p].l && a[p].r <= r) {
			return a[p].val;
		}
		// depend on type of query
		return min(get(2 * p, l, r), get(2 * p + 1, l, r));
	}
} IT;

int n, m, q, idx;
int leaves[N], leafL[N], leafR[N], num[N];
lint dep[N], deps[N], ans[N];
lint sh;
vector<pair<int, ii>> query[N];
vector<ii> adj[N];	

void dfs(int u) {
	num[u] = ++idx;
	if (adj[u].empty()) {
		leaves[++m] = idx;
		deps[m] = dep[u];
		leafL[u] = leafR[u] = m;
		return;
 	}
 	for (ii v : adj[u]) {
 		dep[v.X] = dep[u] + v.Y;
 		dfs(v.X);
 	}
 	leafL[u] = leafL[adj[u][0].X];
 	leafR[u] = leafR[adj[u].back().X];
}

void calc(int u) {
	// cerr << "calc " << u << '\n';
	// debug(sh);
	// FOR(i, 1, m) cerr << IT.get(1, i, i) << ' '; cerr << '\n';

	// answer queries
	for (int i = 0; i < query[u].size(); ++ i) {
		int l = query[u][i].Y.X, r = query[u][i].Y.Y;
		l = lower_bound(leaves + 1, leaves + m + 1, l) - leaves;
		r = upper_bound(leaves + 1, leaves + m + 1, r) - leaves - 1;
		// cerr << "query: " << query[u][i].X << ' ' << l << ' ' << r << '\n';
		ans[query[u][i].X] = sh + IT.get(1, l, r);
	}
	for (ii v : adj[u]) {
		// update IT
		sh += v.Y;
		IT.update(1, leafL[v.X], leafR[v.X], - 2 * v.Y);

		calc(v.X);	
		// restore IT
		sh -= v.Y;
		IT.update(1, leafL[v.X], leafR[v.X], 2 * v.Y);
	}
}	

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> q;
	FOR(i, 2, n) {
		int p, w;
		cin >> p >> w;
		adj[p].push_back(mp(i, w));
	}
	REP(i, q) {
		int v, l, r;
		cin >> v >> l >> r;
		query[v].push_back(mp(i, mp(l, r)));
		;
	}	
	dfs(1);
	IT.init(deps, m);
	calc(1);
	REP(i, q) cout << ans[i] << '\n';
}
