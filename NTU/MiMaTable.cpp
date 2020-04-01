#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

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

const int N = 1005, oo = 1e9 + 7;

struct Node {
	int l, r, val;
};

struct MaxST1D {
	vector<Node> a;
	vector<int> leaf;
	void build(int p, int l, int r, int seg[]) {
		a[p].l = l;
		a[p].r = r;
		if (l < r) {
			int mid = (l + r) / 2;
			build(2 * p, l, mid, seg);
			build(2 * p + 1, mid + 1, r, seg);
			a[p].val = max(a[2 * p].val, a[2 * p + 1].val);
		} else {
			a[p].val = seg[a[p].l];
			leaf[l] = p;
		}
	}
	void update(int p, int idx, int val) {
		if (a[p].l == a[p].r) {
			a[p].val = val;
		} else {
			if (idx <= (a[p].l + a[p].r) / 2)
				update(2 * p, idx, val);
			else update(2 * p + 1, idx, val);
			a[p].val = max(a[2 * p].val, a[2 * p + 1].val);
		}
	}
	int get(int p, int l, int r) {
		if (a[p].l > r || l > a[p].r) return - (1e9 + 7); // -oo value
		if (l <= a[p].l && a[p].r <= r) {
			return a[p].val;
		}
		return max(get(2 * p, l, r), get(2 * p + 1, l, r));
	}
	void init(int n, int seg[]) {
		a.resize(4 * n + 1);
		leaf.resize(n + 2);
		build(1, 1, n, seg);
	}
};

struct Node2 {
	MaxST1D st1;
	int l, r;
};

struct MaxST2D {
	vector<Node2> b;
	vector<int> leaf;
	int sz;
	void build(int p, int l, int r, int board[][N]) {
		b[p].l = l;
		b[p].r = r;

		if (l == r) {
			b[p].st1.init(sz, board[l]);
			leaf[l] = p;
		} else {
			int mid = (l + r) / 2;
			build(2 * p, l, mid, board);
			build(2 * p + 1, mid + 1, r, board);
			cerr << b[p].st1.a.size() << ' ' << sz << '\n';
			FOR(i, 1, 4 * sz) b[p].st1.a[i].val = max(b[2*p].st1.a[i].val, b[2*p + 1].st1.a[i].val);
		}
		cerr << "done build " << l << ' ' << r << '\n';
	}
	void init(int n, int board[][N]) {
		sz = n;
		b.resize(4 * n + 1);
		leaf.resize(n + 2);
		build(1, 1, n, board);
	}
	void update(int x, int y, int val) {
		int uu = leaf[x], vv = b[1].st1.leaf[y];
		b[uu].st1.a[vv].val = val;
		for (int v = vv >> 1; v; v >>= 1) 
			b[uu].st1.a[v].val = max(b[uu].st1.a[2 * v].val, b[uu].st1.a[2 * v + 1].val);
		for (int u = uu >> 1; u; u >>= 1) {
			for (int v = vv; v; v >>= 1) {
				b[u].st1.a[v].val = max(b[2 * u].st1.a[v].val, b[2 * u + 1].st1.a[v].val);
			}
		}
	}
	int get(int p, int x, int y, int u, int v) {
		if (b[p].l > u && x > b[p].r) return -oo;
		if (x <= b[p].l && b[p].l <= u) return b[p].st1.get(1, y, v);
		return max(get(2 * p, x, y, u, v), get(2 * p + 1, x, y, u, v));
	}
} maxst2;

int n, q, a[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) FOR(j, 1, n) {
		cin >> a[i][j];
	}	
	maxst2.init(n, a);
	cin >> q;
	while (q --) {
		char ch;
		int x, y, u, v, w;
		cin >> ch;
		if (ch == 'c') {
			cin >> x >> y >> w;
			maxst2.update(x, y, w);
		} else {
			cin >> x >> y >> u >> v;
			cout << maxst2.get(1, x, y, u, v);
		}
	}
}
