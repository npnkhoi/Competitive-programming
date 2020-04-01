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
#define vDebug(v) for (auto x : v) cerr << x << " "
#define all(x) x.begin(), x.end()

#define task "sol"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 8e4 + 5;

struct Pack {
	int x, lo, hi, type, id;

	Pack(int a, int b, int c, int d, int e):
		x(a), lo(b), hi(c), type(d), id(e) {}

	bool operator < (const Pack &oth) {
		if (x != oth.x) return x < oth.x;
		else return type > oth.type;
	}
};

struct IntervalTree {
	vector<stack<int> > st;
	vector<int> le, ri, leaf;

	void build(int p, int l, int r) {
		le[p] = l;
		ri[p] = r;
		if (l < r) {
			int mid = (l + r) / 2;
			build(2 * p, l, mid);
			build(2 * p + 1, mid + 1, r);
		} else leaf[l] = p;
	}
	IntervalTree (int n) {
		st.resize(4 * n + 5);
		le.resize(4 * n + 5);
		ri.resize(4 * n + 5);
		leaf.resize(n + 5);
		build(1, 1, n);
	}

	void update(int p, int l, int r, int val) {
		if (r < le[p] || ri[p] < l) return;
 		if (l <= le[p] && ri[p] <= r) {
			st[p].push(val);
			return;
		}
		update(2 * p + 1, l, r, val);
		update(2 * p, l, r, val);
	}

	void remove(int p, int l, int r) {
		if (r < le[p] || ri[p] < l) return;
 		if (l <= le[p] && ri[p] <= r) {
			st[p].pop();
			return;
		}
		remove(2 * p + 1, l, r);
		remove(2 * p, l, r);
	}

	int get(int pos) {
		int p = leaf[pos];
		while (p >= 1 && st[p].empty()) {
			p /= 2;
		}
		if (p == 0) return -1;
		return st[p].top();
	}
};	

int n, m, ITsize;
int a[N], b[N], c[N], d[N], x[N], y[N], col[N], lab[N], ans[N], hasPar[N];
set<int> cols[N];
vi adj[N];

void input() {
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	FOR(i, 1, m) {
		cin >> x[i] >> y[i] >> col[i];
	}
}

void compress() {
	vi v;
	FOR(i, 1, n) v.push_back(b[i]), v.push_back(d[i]);
	FOR(i, 1, m) v.push_back(y[i]);
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	ITsize = v.size();
	FOR(i, 1, n) {
		b[i] = upper_bound(all(v), b[i]) - v.begin();
		d[i] = upper_bound(all(v), d[i]) - v.begin();
	}
	FOR(i, 1, m) {
		y[i] = upper_bound(all(v), y[i]) - v.begin();
	}
}

void sweep() {
	vector<Pack> v;
	FOR(i, 1, n) {
		v.push_back(Pack(c[i] + 1, b[i], d[i], 1, i));
		v.push_back(Pack(a[i], b[i], d[i], 0, i));
	}
	FOR(i, 1, m) {
		v.push_back(Pack(x[i], y[i], y[i], -1, i));
	}
	sort(all(v));
	IntervalTree IT(ITsize);

	for (Pack t: v) {
		if (t.type == 1) {
			IT.remove(1, t.lo, t.hi);
		} else if (t.type == 0) {
			int tmp = IT.get(t.lo);
			if (tmp != -1) {
				adj[tmp].push_back(t.id);
				hasPar[t.id] = 1;
			}
			IT.update(1, t.lo, t.hi, t.id);
		} else {
			int tmp = IT.get(t.lo);
			if (tmp != -1) {
				cols[tmp].insert(col[t.id]);
			}
		} 
	}
} 

int root(int u) {
	// cerr << "getting root " << u << ", lab = " << lab[u] << "\n";
	if (lab[u] < 0) return u; 
	return lab[u] = root(lab[u]);
}

void merge(int u, int v) {
	u = root(u), v = root(v);
	if (lab[v] < lab[u]) swap(u, v);
	lab[u] -= (lab[u] == lab[v]);
	lab[v] = u;
	for (set<int> :: iterator it = cols[v].begin(); it != cols[v].end(); ++ it) {
		cols[u].insert(* it);
	}

}

void dfs(int u, int par) {
	for (int v : adj[u]) {
		dfs(v, u);
		merge(u, v);
	}
	ans[u] = cols[root(u)].size();
} 

void solve() {
	memset(lab, -1, sizeof lab);
	FOR(i, 1, n) {
		if (!hasPar[i]) dfs(i, -1);
	}
}

void test() {
	IntervalTree IT(8);
	IT.update(1, 1, 7, 1);
	IT.update(1, 2, 6, 2);
	cerr << IT.get(6);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	
	input();
	compress();
	sweep();
	solve();
	FOR(i, 1, n) cout << ans[i] << "\n";
}
