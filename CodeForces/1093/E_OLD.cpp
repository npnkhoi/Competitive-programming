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
#define task "test"
typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;

const int N = 2e5 + 5;

lint Rand(lint l, lint r) {
    lint res = l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
    if (res < 0) res += r - l + 1;
    return res;
}

struct Node {
	int l, r;
	ordered_set s;
};

struct SegmentTree {
	vector<Node> T;
	void build(int p, int l, int r) {
		T[p].l = l;
		T[p].r = r;
		if (l == r) return;
		int m = (l + r) / 2;
		build(2 * p, l, m);
		build(2 * p + 1, m + 1, r);
	}
	void init(int n) {
		T.resize(4 * n + 2);
		build(1, 1, n);
	}
	void ins(int p, int x, int y) {
		// cerr << "ins " << p << '\n';
		T[p].s.insert(y);
		if (T[p].l == T[p].r) return;
		if (x <= T[2 * p].r) ins(2 * p, x, y);
		else ins(2 * p + 1, x, y);
	}
	void del(int p, int x, int y) {
		T[p].s.erase(y);
		if (T[p].l == T[p].r) return;
		if (x <= T[2 * p].r) del(2 * p, x, y);
		else del(2 * p + 1, x, y);
	}
	int get(int p, int x, int y, int u, int v) {
		if (u < T[p].l || T[p].r < x) return 0;
		if (x <= T[p].l && T[p].r <= u) {
			return T[p].s.order_of_key(v + 1) - T[p].s.order_of_key(y);
		}
		return get(2 * p, x, y, u, v) + get(2 * p + 1, x, y, u, v);
	}
} ST;

int n, m, row[N];
pair<int, int> a[N];

void test() {
	ofstream inp(task".inp");
	int n = 2e5, m = 2e5;
	inp << n << ' ' << m << '\n';
	int seq[n];
	REP(i, n) seq[i] = i + 1;
	random_shuffle(seq, seq + n);
	REP(i, n) inp << seq[i] << ' '; inp << '\n';
	random_shuffle(seq, seq + n);
	REP(i, n) inp << seq[i] << ' '; inp << '\n';
	
	REP(i, m) {
		int ask = Rand(1, 2);
		if (ask == 1) {
			int l1 = Rand(1, n - 1), l2 = Rand(1, n - 1);
			inp << ask << ' ' << l1 << ' ' << Rand(l1 + 1, n) << ' ' << l2 << ' ' << Rand(l2 + 1, n) << '\n';
		} else {
			int x = Rand(1, n - 1);
			inp << ask << ' ' << x << ' ' << Rand(x + 1, n) << '\n';
		}
	}
	inp.close();
}

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	test();
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);

	double Time = clock();
	cin >> n >> m;

	int x;
	FOR(i, 1, n) {
		cin >> x;
		a[x].X = i;
	} 
	FOR(i, 1, n) {
		cin >> x;
		a[x].Y = i;
	}

	ST.init(n);
	FOR(i, 1, n) {
		ST.ins(1, a[i].X, a[i].Y);
		row[a[i].Y] = a[i].X;
	}

	while (m --) {
		int ask, x, y, u, v;
		cin >> ask;
		if (ask == 1) {
			cin >> x >> u >> y >> v;
			cout << ST.get(1, x, y, u, v) << '\n';
		} else {
			cin >> x >> y;
			ST.del(1, row[x], x);
			ST.del(1, row[y], y);
			swap(row[x], row[y]);
			ST.ins(1, row[x], x);
			ST.ins(1, row[y], y);
		}
	}
	cerr << "Time = " << (clock() - Time) / 1000;
}
